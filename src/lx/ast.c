/*
 * Copyright 2008-2017 Katherine Flavel
 *
 * See LICENCE for the full copyright terms.
 */

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include <fsm/fsm.h>

#include <re/re.h>

#include <fsm/bool.h>

#include <adt/xalloc.h>

#include "libfsm/internal.h" /* XXX */

#include "ast.h"

struct ast *
ast_new(void)
{
	struct ast *new;

	new = malloc(sizeof *new);
	if (new == NULL) {
		return NULL;
	}

	new->zl = NULL;
	new->tl = NULL;

	return new;
}

struct ast_token *
ast_addtoken(struct ast *ast, const char *s)
{
	struct ast_token *new;

	assert(s != NULL);

	{
		struct ast_token *t;

		for (t = ast->tl; t != NULL; t = t->next) {
			if (0 == strcmp(t->s, s)) {
				return t;
			}
		}
	}

	new = malloc(sizeof *new);
	if (new == NULL) {
		return NULL;
	}

	/* TODO: could append after new's storage */
	new->s = xstrdup(s);

	new->next = ast->tl;
	ast->tl   = new;

	return new;
}

struct ast_zone *
ast_addzone(struct ast *ast, struct ast_zone *parent)
{
	struct ast_zone *new;

	new = malloc(sizeof *new);
	if (new == NULL) {
		return NULL;
	}

	new->ml   = NULL;
	new->fsm  = NULL;
	new->vl   = NULL;

	new->parent = parent;

	new->next = ast->zl;
	ast->zl   = new;

	return new;
}

struct ast_mapping *
ast_addmapping(struct ast_zone *z, struct fsm *fsm,
	struct ast_token *token, struct ast_zone *to)
{
	struct ast_mapping *m;

	assert(z != NULL);
	assert(fsm != NULL);

	for (m = z->ml; m != NULL; m = m->next) {
		assert(m->fsm != NULL);

		if (token == m->token && to == m->to) {
			break;
		}
	}

	if (m == NULL) {
		m = malloc(sizeof *m);
		if (m == NULL) {
			return NULL;
		}

		m->fsm = fsm_new(fsm->opt);
		if (m->fsm == NULL) {
			free(m);
			return NULL;
		}

		m->token    = token;
		m->to       = to;
		m->conflict = NULL;

		m->next = z->ml;
		z->ml   = m;
	}

	/* TODO: re_addcolour(fsm, m) */

	m->fsm = fsm_union(m->fsm, fsm, NULL);
	if (m->fsm == NULL) {
		return NULL;
	}

	return m;
}

/* TODO: merge with adt/set.c */
struct mapping_set *
ast_addconflict(struct mapping_set **head, struct ast_mapping *m)
{
	struct mapping_set *new;

	assert(head != NULL);
	assert(m != NULL);

	/* TODO: explain we find duplicate; return success */
	{
		struct mapping_set *s;

		for (s = *head; s != NULL; s = s->next) {
			if (s->m == m) {
				return s;
			}
		}
	}

	new = malloc(sizeof *new);
	if (new == NULL) {
		return NULL;
	}

	new->m    = m;

	new->next = *head;
	*head     = new;

	return new;
}

#define MAX_MAPPINGS 64 	/* FIXME */
static fsm_end_id_t mapping_count = 0;
static struct ast_mapping *mappings[MAX_MAPPINGS];

int
ast_setendmapping(struct fsm *fsm, struct ast_mapping *m)
{
	const fsm_end_id_t id = mapping_count;

	if (fsm_setendid(fsm, id)) {
		if (LOG()) {
			fprintf(stderr, "ast_setendmapping: saving mapping %p at mappings[%d]\n",
			    (void *)m, id);
		}
		mappings[id] = m;
		mapping_count++;
		return 1;
	}
	return 0;
}

struct ast_mapping *
ast_getendmappingbyendid(fsm_end_id_t id)
{
	assert(id < mapping_count);
	return mappings[id];
}

struct ast_mapping *
ast_getendmapping(const struct fsm *fsm, fsm_state_t s)
{
	#define ID_BUF_COUNT 8
	fsm_end_id_t id_buf[ID_BUF_COUNT];
	enum fsm_getendids_res res;
	size_t written;
	struct ast_mapping *m;

	res = fsm_getendids(fsm,
	    s, ID_BUF_COUNT, id_buf, &written);
	if (res == FSM_GETENDIDS_NOT_FOUND) {
		return NULL;
	}

	if (res == FSM_GETENDIDS_ERROR_INSUFFICIENT_SPACE) {
		assert(!"FIXME: capacity");
	}

	assert(res == FSM_GETENDIDS_FOUND);
	assert(written < ID_BUF_COUNT);
	assert(written > 0);

	m = ast_getendmappingbyendid(id_buf[0]);

	if (LOG()) {
		fprintf(stderr, "ast_getendmapping: got mapping %p mappings[%d]\n",
		    (void *)m, id_buf[0]);
	}
	return m;
}
