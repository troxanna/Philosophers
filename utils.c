#include "philo.h"

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


void	ft_error(int err)
{
	if (err == 1)
		write(1, "Error: malloc error\n", 21);
	else if (err == 2)
		write(1, "Error: invalid count of arguments\n", 35);
	else if (err == 3)
		write(1, "Error: invalid value of arguments\n", 35);
	else if (err == 4)
		write(1, "Error: mutex initialization error\n", 35);
	else if (err == 5)
		write(1, "Error: thread create error\n", 35);
	exit(1);
}

void	validate_data(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 5 || argc > 6)
		ft_error(2);
	while (++i < argc)
	{
		j = -1;
		while (++j < ft_strlen(argv[i]))
			if (argv[i][j] < 48 || argv[i][j] > 57)
				ft_error(3);
	}
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) < 1
		|| ft_atoi(argv[3]) < 1 || ft_atoi(argv[4]) < 1)
		ft_error(2);
	if  (argc == 6)
		if (ft_atoi(argv[5]) < 1)
			ft_error(2);
}

int	ft_atoi(const char *str)
{
	unsigned int	result;
	int	sign;

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

size_t		ft_strlen(const char *str)
{
	size_t c;

	c = 0;
	while (*str != '\0')
	{
		str++;
		c++;
	}
	return (c);
}

void	ft_putnbr_fd(long n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * (-1);
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
	else
	{
		ft_putchar_fd(n + 48, fd);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], sizeof(s[i]));
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}
