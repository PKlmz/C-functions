/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 20:05:39 by pkaerts           #+#    #+#             */
/*   Updated: 2021/01/21 20:05:40 by pkaerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clean(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	ft_clean(lst->next, del);
	del(lst->content);
	free(lst);
}

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !del || !*lst)
		return ;
	if ((*lst)->next)
		ft_clean((*lst)->next, del);
	del((*lst)->content);
	*lst = NULL;
}
