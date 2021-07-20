#include "../includes/philo.h"


void	ft_error(int err)
{
	if (err == 1)
		write(1, "malloc error\n", 16);
	if (err == 2)
		write(1, "Error: not enough arguments\n", 29);
	exit(1);
}

long	get_time(long start)
{
	struct timeval tv;
	long   mls;

	gettimeofday(&tv, NULL);
	mls = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (mls - start);
}

void	ft_usleep(int in)
{
	time_t start;
	time_t end;

	start = get_time(0);
	end = get_time(0) + in;
	while (start < end)
	{
		usleep(10);
		start = get_time(0);
	}
}