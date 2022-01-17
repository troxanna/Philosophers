/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:55:26 by troxanna          #+#    #+#             */
/*   Updated: 2022/01/16 18:56:38 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	ft_free(t_philo *philo)
{
	free(philo[0].input);
	free(philo[0].sem);
	free(philo);
}

static void	wait_processes(t_philo *philo, int cur_count, int count)
{
	int	i;
	int	status;

	i = -1;
	waitpid(0, &status, WUNTRACED);
	if (WEXITSTATUS(status) == 1)
	{
		while (++i < count)
			kill(philo[i].pid, SIGKILL);
	}
	else if (WEXITSTATUS(status) == 2)
	{
		if (cur_count == 0)
			while (++i < count)
				kill(philo[i].pid, SIGKILL);
		else
			wait_processes(philo, --cur_count, count);
	}
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	int		i;
	int		count;

	count = ft_atoi(argv[1]);
	validate_data(argc, argv);
	philo = init(argv, argc);
	i = -1;
	while (++i < count)
	{
		philo[i].pid = fork();
		if (philo[i].pid < 0)
			return (0);
		if (!philo[i].pid)
			philo_life(&philo[i]);
	}
	wait_processes(philo, count, count);
	ft_free(philo);
	return (0);
}
