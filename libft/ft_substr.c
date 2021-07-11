/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:06:47 by troxanna          #+#    #+#             */
/*   Updated: 2020/11/05 16:07:10 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	size_t			j;

	if (!s)
		return (NULL);
	j = 0;
	i = start;
	sub = (char *)malloc((len + 1) * (sizeof(char)));
	if (!sub)
		return (NULL);
	if (start > ft_strlen(s))
	{
		sub[j] = '\0';
		return (sub);
	}
	while (s[i] && j < len)
	{
		sub[j] = s[i];
		i++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}
