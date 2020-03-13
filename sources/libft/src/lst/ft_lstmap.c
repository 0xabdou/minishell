/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:33:32 by aouahib           #+#    #+#             */
/*   Updated: 2019/10/27 20:13:05 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	enlist(t_list **lst, t_list **tmp, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		*tmp = new;
	}
	else
	{
		(*tmp)->next = new;
		*tmp = (*tmp)->next;
	}
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	t_list	*tmp;

	new_lst = 0;
	tmp = 0;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		enlist(&new_lst, &tmp, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}
