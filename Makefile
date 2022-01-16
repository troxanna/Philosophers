NAME = philo
NAME_B = philo_bonus
HEAD = ./includes/
HEAD_B = ./bonus/includes/
SRCS = ./srcs/
SRCS_B = ./bonus/srcs/

CFLAGS = -Wall -Werror -Wextra

C_FILE = $(SRCS)init.c $(SRCS)utils_print.c $(SRCS)philo_life.c $(SRCS)utils.c ./main.c 

C_B_FILE = $(SRCS_B)init.c $(SRCS_B)utils_print.c $(SRCS_B)philo_life.c $(SRCS_B)utils.c ./bonus/main.c

O_FILE = $(C_FILE:.c=.o)

O_B_FILE = $(C_B_FILE:.c=.o)

%.o: %.c $(HEAD) $(HEAD_B)
	gcc -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(O_FILE)
	gcc $(O_FILE) -o $(NAME)

$(NAME_B): $(O_B_FILE) $(HEAD_B)
	gcc $(O_B_FILE) -o $(NAME_B)

bonus: $(NAME_B)

clean:
	@rm -f $(O_FILE) $(O_B_FILE)

fclean: clean
	@rm -f $(NAME) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re
