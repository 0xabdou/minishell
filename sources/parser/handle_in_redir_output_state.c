#include "parser.h"

void	handle_in_redir_output_state(t_parse_params *params)
{
	append_token(params, TYPE_SPECIAL, ">");
	if (params->cat == CHAR_GENERAL)
	{
		params->next_state = STATE_IN_STRING;
		ls_append(&params->token, params->c);
	}
	else if (params->cat == CHAR_WHITE_SPACE)
	{
		params->next_state = STATE_GENERAL;
	}
}
