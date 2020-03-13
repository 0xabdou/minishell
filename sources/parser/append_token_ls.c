#include "parser.h"

void	append_token_ls(t_list **tokens, t_linked_string *ls)
{
	//TODO: handle allocation error
	ft_lstadd_back(tokens, ft_lstnew(ls_to_string(ls)));
}