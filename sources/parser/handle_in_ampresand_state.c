#include "parser.h"

void	handle_in_ampersand_state(t_parse_params *p)
{
	if (p->cat == CHAR_AMPERSAND)
	{
		p->next_state = STATE_IN_AND;
	}
	else
	{
		p->next_state = STATE_SYNTAX_ERROR;
	}
}
