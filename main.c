#include "includes/philo.h"

int		main(int argc, char **argv)
{
	int	c_eat;
	t_input	*input;

	if (argc < 5)
		ft_error(2);
	input = init_input(ft_atoi(argv[1]), ft_atoi(argv[2]),
				ft_atoi(argv[3]), ft_atoi(argv[4]));
	if (argc == 6)
		input->count_eat = ft_atoi(argv[5]);
	
}