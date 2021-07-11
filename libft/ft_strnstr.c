/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:10:08 by troxanna          #+#    #+#             */
/*   Updated: 2020/11/16 12:37:53 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t slen)
{
	size_t i;
	size_t j;

	i = 0;
	if (find[i] == '\0')
		return ((char *)s);
	while (i < slen && s[i])
	{
		j = 0;
		while (find[j] && s[i + j] == find[j] && s[i + j] && (i + j) < slen)
			j++;
		if (find[j] == '\0')
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
