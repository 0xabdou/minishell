#include "parser.h"

void	append_token(t_parse_params *params, t_token_type type, char *maybe_str)
{
    t_token	*token;
    char	*value;

    value = maybe_str
    		? ft_strdup(maybe_str)
    		: ls_to_string(params->token);
    token = malloc(sizeof(t_token));
    token->value = value;
    token->type = type;
	ft_lstadd_back(&params->tokens, ft_lstnew(token));
	//TODO: handle allocation error
	params->token = 0;
}