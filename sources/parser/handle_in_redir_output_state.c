#include "parser.h"

void	handle_in_redir_output_state(t_parse_params *params)
{
	append_token(params, TYPE_SPECIAL, "<");
}
