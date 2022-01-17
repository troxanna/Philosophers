/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:00:01 by troxanna          #+#    #+#             */
/*   Updated: 2022/01/16 18:30:07 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time(long start)
{
	struct timeval	tv;
	long			mls;

	gettimeofday(&tv, NULL);
	mls = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (mls - start);
}

void	ft_usleep(int in)
{
	time_t	start;
	time_t	end;

	start = get_time(0);
	end = get_time(0) + in;
	while (start < end)
	{
		usleep(10);
		start = get_time(0);
	}
}

void	*ft_error(int err)
{
	if (err == 1)
		write(1, "Error: malloc error or mutex initialization error\n", 51);
	else if (err == 2)
		write(1, "Error: invalid count of arguments\n", 35);
	else if (err == 3)
		write(1, "Error: invalid value of arguments\n", 35);
	return (NULL);
}

char	*validate_data(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 5 || argc > 6)
		return (ft_error(2));
	while (++i < argc)
	{
		j = -1;
		while (++j < (int)ft_strlen(argv[i]))
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (ft_error(3));
	}
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) < 1
		|| ft_atoi(argv[3]) < 1 || ft_atoi(argv[4]) < 1)
		return (ft_error(2));
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) < 1)
			return (ft_error(2));
	}
	return ("SUCCESS");
}

int	ft_atoi(const char *str)
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
