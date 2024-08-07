/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:15:01 by pkaerts           #+#    #+#             */
/*   Updated: 2021/01/21 18:15:03 by pkaerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*pos;

	if (!alst || !new)
		return ;
	pos = *alst;
	if (pos)
	{
		while (pos->next)
			pos = pos->next;
		pos->next = new;
		new->next = NULL;
	}
	else
		*alst = new;
}
