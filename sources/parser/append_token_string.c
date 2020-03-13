#include "parser.h"

void	append_token_str(t_list **tokens, char *str)
{
	//TODO: handle allocation error
	ft_lstadd_back(tokens, ft_lstnew(str));
}
