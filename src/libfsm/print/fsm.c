/*
 * Copyright 2008-2017 Katherine Flavel
 *
 * See LICENCE for the full copyright terms.
 */

#include <assert.h>
#include <limits.h>
#include <stdio.h>

#include "libfsm/internal.h" /* XXX: up here for bitmap.h */

#include <print/esc.h>

#include <adt/set.h>
#include <adt/bitmap.h>
#include <adt/stateset.h>
#include <adt/edgeset.h>

#include <fsm/fsm.h>
#include <fsm/pred.h>
#include <fsm/walk.h>
#include <fsm/print.h>
#include <fsm/options.h>

/* TODO: centralise */
static int
findany(const struct fsm *fsm, fsm_state_t state, fsm_state_t *a)
{
	struct fsm_edge e;
	struct edge_iter it;
	fsm_state_t f;
	struct bm bm;

	assert(fsm != NULL);
	assert(state < fsm->statecount);

	/*
	 * This approach is a little unsatisfying because it will only identify
	 * situations with one single "any" edge between states. I'd much prefer
	 * to be able to emit "any" edges for situations like:
	 *
	 *  1 -> 2 'x';
	 *  1 -> 3;
	 *
	 * where a given state also has an unrelated edge transitioning elsewhere.
	 * The current implementation conservatively bails out on that situation
	 * (because f != e.state), and will emit each edge separately.
	 */

	bm_clear(&bm);

	edge_set_reset(fsm->states[state].edges, &it);
	if (!edge_set_next(&it, &e)) {
		return 0;
	}

	/* if the first edge is not the first character,
	 * then we can't possibly have an "any" transition */
	if (e.symbol != '\0') {
		return 0;
	}

	f = e.state;

	for (edge_set_reset(fsm->states[state].edges, &it); edge_set_next(&it, &e); ) {
		if (f != e.state) {
			return 0;
		}

		/* we reject duplicate edges, even though they're to the same state */
		if (bm_get(&bm, e.symbol)) {
			return 0;
		}

		bm_set(&bm, e.symbol);
	}

	if (bm_count(&bm) != FSM_SIGMA_COUNT) {
		return 0;
	}

	assert(f < fsm->statecount);

	*a = f;
	return 1;
}

void
fsm_print_fsm(FILE *f, const struct fsm *fsm)
{
	fsm_state_t s, start;
	size_t end;

	assert(f != NULL);
	assert(fsm != NULL);

	if (!fsm->opt->anonymous_states) {
		/*
		 * States are output in order here so as to force ordering when
		 * parsing the .fsm format and creating new states. This ensures
		 * that the new states (numbered in order) match the numbering here.
		 */
		for (s = 0; s < fsm->statecount; s++) {
			fprintf(f, "%u;%s", s,
				s + 1 < fsm->statecount ? " " : "\n");
		}

		fprintf(f, "\n");
	}

	for (s = 0; s < fsm->statecount; s++) {
		struct fsm_edge e;
		struct edge_ordered_iter eoi;

		{
			struct state_iter jt;
			fsm_state_t st;

			for (state_set_reset(fsm->states[s].epsilons, &jt); state_set_next(&jt, &st); ) {
				fprintf(f, "%-2u -> %2u;\n", s, st);
			}
		}

		{
			fsm_state_t a;

			if (findany(fsm, s, &a)) {
				fprintf(f, "%-2u -> %2u ?;\n", s, a);
				continue;
			}
		}

		assert(s < fsm->statecount);

		for (edge_set_ordered_iter_reset(fsm->states[s].edges, &eoi);
		     edge_set_ordered_iter_next(&eoi, &e); ) {
			assert(e.state < fsm->statecount);

			fprintf(f, "%-2u -> %2u", s, e.state);

			fputs(" \"", f);
			fsm_escputc(f, fsm->opt, (char)e.symbol);
			putc('\"', f);

			fprintf(f, ";");

			if (fsm->opt->comments) {
				fsm_state_t start;

				if (fsm_getstart(fsm, &start)) {
					if (e.state == start) {
						fprintf(f, " # start");
					} else if (!fsm_has(fsm, fsm_hasepsilons)) {
						char buf[50];
						int n;

						n = fsm_example(fsm, e.state, buf, sizeof buf);
						if (-1 == n) {
							perror("fsm_example");
							return;
						}

						if (n > 0) {
							fprintf(f, " # e.g. \"");
							escputs(f, fsm->opt, fsm_escputc, buf);
							fprintf(f, "%s\"",
								n >= (int) sizeof buf - 1 ? "..." : "");
						}
					}
				}
			}

			fprintf(f, "\n");
		}
	}

	fprintf(f, "\n");

	if (!fsm_getstart(fsm, &start)) {
		return;
	}

	fprintf(f, "start: %u;\n", start);

	end = fsm->endcount;

	if (end == 0) {
		return;
	}

	fprintf(f, "end:   ");
	for (s = 0; s < fsm->statecount; s++) {
		if (fsm_isend(fsm, s)) {
			end--;

			fprintf(f, "%u%s", s, end > 0 ? ", " : ";\n");
		}
	}
}

