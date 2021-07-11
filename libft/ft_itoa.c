/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:53:29 by troxanna          #+#    #+#             */
/*   Updated: 2020/11/23 22:24:20 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_fill_in(int n, int len)
{
	char	*str;

	str = (char *)malloc((len + 1) * sizeof(char));
	if (str)
	{
		str[len] = '\0';
		len--;
		if (n < 0)
		{
			str[0] = '-';
			if (n == -2147483648)
			{
				str[1] = '2';
				n = -147483648;
			}
			n = n * (-1);
		}
		while (n)
		{
			str[len--] = n % 10 + 48;
			n = n / 10;
		}
		return (str);
	}
	return (NULL);
}

static char	*ft_itoa_null(void)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (str)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	return (NULL);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		tmp;

	tmp = n;
	if (n < 0)
		len = 1;
	else
		len = 0;
	while (tmp)
	{
		tmp = tmp / 10;
		len++;
	}
	if (n == 0)
		return (ft_itoa_null());
	str = ft_itoa_fill_in(n, len);
	if (str)
		return (str);
	return (NULL);
}
