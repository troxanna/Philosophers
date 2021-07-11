/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:40:37 by troxanna          #+#    #+#             */
/*   Updated: 2020/11/03 17:17:51 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *arr, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp_arr;
	unsigned char	chr;

	tmp_arr = (unsigned char *)arr;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (tmp_arr[i] == chr)
			return (tmp_arr + i);
		i++;
	}
	return (NULL);
}
