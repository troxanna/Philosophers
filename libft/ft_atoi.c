/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:06:18 by troxanna          #+#    #+#             */
/*   Updated: 2020/12/12 21:37:50 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	unsigned int	result;
	int				sign;

	result = 0;
	sign = 1;
	while (*str == '\n' || *str == '\f' || *str == '\t' || *str == ' '
			|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + (*str - 48);
		str++;
		if (result > 2147483648 && sign == -1)
			return (0);
		else if (result > 2147483647 && sign == 1)
			return (-1);
	}
	return (result * sign);
}
