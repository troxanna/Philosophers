#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_BLUE "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN "\x1b[36m"
# define ANSI_COLOR_RESET "\x1b[0m"

typedef pthread_mutex_t mutex_t;

typedef	struct s_input
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_count_eat;
	int	end;
}				t_input;

typedef struct		s_philo
{
	int	id;
	pthread_t	pt;
	size_t	left_fork;
	size_t	right_fork;
	long	time_start;
	int		current_count_eat;
	long	time_last_eat;
	mutex_t	*forks;
	mutex_t	*message;
	t_input	*input;
}					t_philo;


void	ft_error(int err);
void	validate_data(int argc, char **argv);
void	ft_usleep(int in);
int	ft_atoi(const char *str);
long	get_time(long start);
void	ft_putnbr_fd(long n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
t_philo	*init(char **argv, int argc);

#endif