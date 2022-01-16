/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troxanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:30:45 by troxanna          #+#    #+#             */
/*   Updated: 2022/01/16 18:31:46 by troxanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define ANSI_COLOR_RED "\x1b[31m"

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
	int			id;
	pthread_t	pt;
	size_t		left_fork;
	size_t		right_fork;
	long		time_start;
	int			current_count_eat;
	long		time_last_eat;
	t_mutex		*forks;
	t_mutex		*message;
	t_input		*input;
}					t_philo;

void	*ft_error(int err);
char	*validate_data(int argc, char **argv);
void	ft_usleep(int in);
int		ft_atoi(const char *str);
long	get_time(long start);
void	ft_putnbr_fd(long n, int fd);
size_t	ft_strlen(const char *str);
t_philo	*init(char **argv, int argc);
void	print_message(char *str, t_philo *philo);
void	*philo_life(void *v_philo);
void	monitoring_death(t_philo *philo, int count);

#endif
