/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:06:56 by troxanna          #+#    #+#             */
/*   Updated: 2020/11/19 20:44:01 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*first_ptr;

	if (!lst || !f || !del)
		return (NULL);
	first_ptr = ft_lstnew((f(lst->content)));
	if (!first_ptr)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		ptr = ft_lstnew((f(lst->content)));
		if (!ptr)
		{
			ft_lstclear(&first_ptr, del);
			return (NULL);
		}
		ft_lstadd_back(&first_ptr, ptr);
		lst = lst->next;
	}
	return (first_ptr);
}
