/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:57:10 by troxanna          #+#    #+#             */
/*   Updated: 2020/11/04 18:58:43 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t number, size_t size)
{
	void	*t;

	t = malloc(number * size);
	if (t)
	{
		ft_bzero(t, number * size);
		return (t);
	}
	else
		return (NULL);
}
