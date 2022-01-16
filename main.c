/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:04:12 by troxanna          #+#    #+#             */
/*   Updated: 2022/01/16 16:17:40 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;
	int		i;

	if (!validate_data(argc, argv))
		return (1);
	philo = init(argv, argc);
	if (!philo)
		return (1);
	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		philo[i].time_start = get_time(0);
		philo[i].time_last_eat = get_time(0);
		pthread_create(&philo[i].pt, NULL, &philo_life, &philo[i]);
	}
	monitoring_death(philo, ft_atoi(argv[1]));
	return (0);
}
