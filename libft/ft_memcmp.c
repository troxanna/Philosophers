/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:54:37 by troxanna          #+#    #+#             */
/*   Updated: 2020/11/03 17:36:33 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *memptr1, const void *memptr2,
								size_t num)
{
	unsigned char	*tmp_memptr1;
	unsigned char	*tmp_memptr2;

	tmp_memptr1 = (unsigned char *)memptr1;
	tmp_memptr2 = (unsigned char *)memptr2;
	while (num)
	{
		if (*tmp_memptr1 == *tmp_memptr2)
		{
			tmp_memptr1++;
			tmp_memptr2++;
		}
		else
		{
			if (*tmp_memptr1 > *tmp_memptr2)
				return (*tmp_memptr1 - *tmp_memptr2);
			else
				return (*tmp_memptr1 - *tmp_memptr2);
		}
		num--;
	}
	return (0);
}
