/*
 * Automatically generated from the files:
 *	form/glob/parser.sid
 * and
 *	libre/parser.act
 * by:
 *	sid
 */

/* BEGINNING OF HEADER */

#line 66 "libre/parser.act"


	typedef struct re *        re;
	typedef struct lex_state * lex_state;
	typedef struct act_state * act_state;

	struct act_state {
		int lex_tok;
		int lex_tok_save;
		enum re_err err;

		/*
		 * XXX: This non-portably assumes all struct lex_state * pointers may
		 * store the same representation. Really it ought to be void * instead.
		 */
		int (*lex_nexttoken)(struct lex_state *);
		char (*lex_tokval)(struct lex_state *);
	};

	#define CURRENT_TERMINAL (act_state->lex_tok)
	#define ERROR_TERMINAL   (TOK_ERROR)
	#define ADVANCE_LEXER    do { act_state->lex_tok = act_state->lex_nexttoken(lex_state); } while (0)
	#define SAVE_LEXER(tok)  do { act_state->lex_tok_save = act_state->lex_tok;  \
	                              act_state->lex_tok = tok;                      } while (0)
	#define RESTORE_LEXER    do { act_state->lex_tok = act_state->lex_tok_save;  } while (0)

#line 40 "form/glob/parser.h"

/* BEGINNING OF FUNCTION DECLARATIONS */

extern void p_re__glob(re, lex_state, act_state);
/* BEGINNING OF TRAILER */

#line 299 "libre/parser.act"


#line 50 "form/glob/parser.h"

/* END OF FILE */
