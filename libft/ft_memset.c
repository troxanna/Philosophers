/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:20:30 by troxanna          #+#    #+#             */
/*   Updated: 2020/12/02 21:13:08 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memset(void *dest, int c, size_t n)
{
	unsigned char		*tmp;

	tmp = dest;
	while (n)
	{
		*tmp = (unsigned char)c;
		tmp++;
		n--;
	}
	return (dest);
}
