/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:57:04 by troxanna          #+#    #+#             */
/*   Updated: 2022/01/16 18:57:08 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/types.h>
# include <pthread.h>
# include <signal.h>

# define SEM_FORKS 0
# define SEM_PRINT 1
# define SEM_DEAD 2

typedef pthread_mutex_t	t_mutex;

typedef struct s_input
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_count_eat;
	int	end;
}				t_input;

typedef struct s_philo
{
	int		id;
	pid_t	pid;
	long	time_start;
	int		current_count_eat;
	long	time_last_eat;
	sem_t	**sem;
	t_input	*input;
}					t_philo;

void	ft_error(int err);
void	validate_data(int argc, char **argv);
void	ft_usleep(int in);
int		ft_atoi(const char *str);
long	get_time(long start);
void	ft_putnbr_fd(long n, int fd);
size_t	ft_strlen(const char *str);
t_philo	*init(char **argv, int argc);
void	philo_life(t_philo *philo);
void	print_message(char *str, t_philo *philo);

#endif
