/* Generated by libfsm */

#include LF_HEADER

#include <stddef.h>

#include <fsm/fsm.h>

struct fsm *
class_ascii_fsm(const struct fsm_options *opt)
{
	struct fsm *fsm;
	size_t i;

	struct fsm_state *s[2] = { 0 };

	fsm = fsm_new(opt);
	if (fsm == NULL) {
		return NULL;
	}

	for (i = 0; i < 2; i++) {
		s[i] = fsm_addstate(fsm);
		if (s[i] == NULL) {
			goto error;
		}
	}

	if (!fsm_addedge_literal(fsm, s[0], s[1], '\000')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\001')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\002')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\003')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\004')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\005')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\006')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\007')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\010')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\t')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\n')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\v')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\f')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\r')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\016')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\017')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\020')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\021')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\022')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\023')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\024')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\025')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\026')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\027')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\030')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\031')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\032')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\033')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\034')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\035')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\036')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\037')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], ' ')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '!')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\"')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '#')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '$')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '%')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '&')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\'')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '(')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], ')')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '*')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '+')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], ',')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '-')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '.')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '/')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '0')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '1')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '2')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '3')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '4')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '5')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '6')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '7')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '8')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '9')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], ':')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], ';')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '<')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '=')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '>')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '?')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '@')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'A')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'B')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'C')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'D')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'E')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'F')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'G')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'H')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'I')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'J')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'K')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'L')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'M')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'N')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'O')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'P')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'Q')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'R')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'S')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'T')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'U')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'V')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'W')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'X')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'Y')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'Z')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '[')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\\')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], ']')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '^')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '_')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '`')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'a')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'b')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'c')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'd')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'e')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'f')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'g')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'h')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'i')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'j')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'k')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'l')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'm')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'n')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'o')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'p')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'q')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'r')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 's')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 't')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'u')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'v')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'w')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'x')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'y')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], 'z')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '{')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '|')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '}')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '~')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\177')) { goto error; }

	fsm_setstart(fsm, s[0]);
	fsm_setend(fsm, s[1], 1);

	return fsm;

error:

	fsm_free(fsm);

	return NULL;
}
