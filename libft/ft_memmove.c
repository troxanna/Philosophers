/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:15:24 by troxanna          #+#    #+#             */
/*   Updated: 2020/11/11 17:34:36 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tmp_dest;
	const unsigned char	*tmp_src;

	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (tmp_src >= tmp_dest || tmp_src > (tmp_dest + n))
		return (ft_memcpy(tmp_dest, tmp_src, n));
	else
	{
		i = n;
		while (i)
		{
			tmp_dest[i - 1] = tmp_src[i - 1];
			i--;
		}
	}
	dest = tmp_dest;
	return (dest);
}
