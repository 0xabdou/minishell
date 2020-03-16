#include "parser.h"

void	handle_piped_state(t_parse_params *params) {
	if (params->cat == CHAR_PIPE || params->cat == CHAR_AMPERSAND)
		params->next_state = STATE_SYNTAX_ERROR;
	else if (params->cat == CHAR_WHITE_SPACE)
		params->next_state = STATE_PIPED;
	else
	{
		params->next_state = STATE_GENERAL;
		params->i--;
	}
}
