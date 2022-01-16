/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:55:36 by troxanna          #+#    #+#             */
/*   Updated: 2022/01/16 18:02:32 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	while (*str != '\0')
	{
		str++;
		c++;
	}
	return (c);
}

void	print_message(char *str, t_philo *philo)
{
	sem_wait(philo->sem[SEM_PRINT]);
	ft_putnbr_fd(get_time(philo->time_start), 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->id, 1);
	write(1, " ", 1);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	sem_post(philo->sem[SEM_PRINT]);
}

void	ft_putnbr_fd(long n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = n * (-1);
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		c = n % 10 + 48;
		ft_putnbr_fd(n / 10, fd);
		write(1, &c, 1);
	}
	else
	{
		c = n + 48;
		write(1, &c, 1);
	}
}
