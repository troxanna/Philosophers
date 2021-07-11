#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "../libft/libft.h"

typedef pthread_mutex_t mutex_t;

typedef struct s_input
{
	int		num_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		count_eat;
}				t_input;

typedef struct s_philo
{
	int			id;
	char		*name;
	pthread_t	*pt;
	mutex_t		*left_fork;
	mutex_t		*right_fork;
}				t_philo;

typedef struct s_all
{
	t_philo		*philo;
	long		start;
	t_input		*input;
}				t_all;

typedef struct s_array
{
	int	*array;
	int len;
}				t_array;

void	ft_error(int err);
long	get_time(long start);
void	ft_usleep(int in);
t_input	*init_input(int n_philo, int t_die, int t_eat, int t_sleep);
void	init_philo(mutex_t *l_fork, mutex_t *r_fork, char *name, int id);
void	free_philo(t_philo *philo);



#endif 