/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:54:18 by troxanna          #+#    #+#             */
/*   Updated: 2022/01/16 18:54:23 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	philo_eat(t_philo *philo)
{
	sem_wait(philo->sem[SEM_FORKS]);
	print_message("has taken first a fork\n", philo);
	sem_wait(philo->sem[SEM_FORKS]);
	print_message("has taken seconde a fork\n", philo);
	print_message("is eating\n", philo);
	philo->time_last_eat = get_time(0);
	philo->current_count_eat += 1;
	ft_usleep(philo->input->time_to_eat);
	sem_post(philo->sem[SEM_FORKS]);
	sem_post(philo->sem[SEM_FORKS]);
}

static void	*monitoring_death(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *)v_philo;
	while (1)
	{
		if (get_time(0) - philo->time_last_eat > philo->input->time_to_die)
		{
			sem_wait(philo->sem[SEM_DEAD]);
			print_message("is dead\n", philo);
			sem_wait(philo->sem[SEM_PRINT]);
			exit(1);
		}
	}
	return (NULL);
}

void	philo_life(t_philo *philo)
{
	pthread_t	pt_death;

	pthread_create(&pt_death, NULL, &monitoring_death, philo);
	pthread_detach(pt_death);
	while (1)
	{
		if (philo->input->max_count_eat != -1
			&& philo->current_count_eat == philo->input->max_count_eat)
			exit(2);
		philo_eat(philo);
		print_message("is sleeping\n", philo);
		ft_usleep(philo->input->time_to_sleep);
		print_message("is thinking\n", philo);
	}
}
