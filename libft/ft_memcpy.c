/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:43:32 by troxanna          #+#    #+#             */
/*   Updated: 2020/11/03 16:11:08 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_dest;

	if (!src && !dest)
		return (NULL);
	tmp_dest = dest;
	i = 0;
	while (i < n)
	{
		tmp_dest[i] = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}
