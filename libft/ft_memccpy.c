/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:59:40 by troxanna          #+#    #+#             */
/*   Updated: 2020/11/03 16:45:32 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dest, const void *src,
									int c, size_t n)
{
	size_t				i;
	unsigned char		chr;
	unsigned char		*tmp_dest;
	const unsigned char	*tmp_src;

	chr = (unsigned char)c;
	tmp_dest = dest;
	tmp_src = src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		tmp_dest[i] = tmp_src[i];
		if (chr == tmp_src[i])
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
