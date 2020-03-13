#include "parser.h"

void	handle_initial_state(t_parse_params *p)
{
	if (p->cat == CHAR_PIPE || p->cat == CHAR_AMPERSAND
		|| p->cat == CHAR_SEMICOLON)
		p->next_state = STATE_SYNTAX_ERROR;
	else
		p->next_state = STATE_GENERAL;
	p->i--;
}
