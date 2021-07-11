/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:32:11 by troxanna          #+#    #+#             */
/*   Updated: 2020/11/19 19:44:23 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list *ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (ptr)
	{
		ptr->content = content;
		ptr->next = NULL;
		return (ptr);
	}
	return (NULL);
}
