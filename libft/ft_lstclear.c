/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:18:40 by troxanna          #+#    #+#             */
/*   Updated: 2020/11/19 20:53:02 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *ptr;

	ptr = *lst;
	if (!lst || !(*lst) || !del)
		return ;
	while (ptr)
	{
		ptr = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		(*lst) = ptr;
	}
	lst = NULL;
}
