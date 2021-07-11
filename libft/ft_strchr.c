/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:05:00 by troxanna          #+#    #+#             */
/*   Updated: 2020/11/03 19:08:12 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == symbol)
			return ((char *)string + i);
		else
			i++;
	}
	if (string[i] == symbol)
		return ((char *)string + i);
	return (NULL);
}
