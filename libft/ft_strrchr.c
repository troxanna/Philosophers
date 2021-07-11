/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:27:21 by troxanna          #+#    #+#             */
/*   Updated: 2020/11/11 17:34:57 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char						*ft_strrchr(const char *str, int ch)
{
	int						i;
	unsigned char			chr;
	char					*tmp;

	i = 0;
	tmp = (char *)str;
	chr = (unsigned char)ch;
	while (tmp[i])
		i++;
	if (ch == '\0')
		return (tmp + i);
	while (i >= 0)
	{
		if (tmp[i] == ch)
			return (tmp + i);
		i--;
	}
	return (NULL);
}
