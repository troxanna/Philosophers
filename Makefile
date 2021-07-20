# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/01 19:12:24 by kshanti           #+#    #+#              #
#    Updated: 2021/07/05 19:17:26 by kshanti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_main

HEAD = ./includes/
SRCS = ./philo/srcs/

CFLAGS = -g

C_FILE = $(SRCS)init_data.c $(SRCS)utils.c ./philo/main.c 

O_FILE = $(C_FILE:.c=.o)

all:
	$(MAKE) $(NAME) -j 4

$(NAME): $(O_FILE)
	$(MAKE) -C ./libft bonus
	gcc $(O_FILE) ./libft/libft.a $(RL) -o $(NAME)

%.o: %.c $(HEAD)
	gcc -c $(СFLAGS) $< -o $@

clean:
	@rm -f ./philo/$(O_FILE)
	$(MAKE) -C ./libft clean

fclean: clean
	@rm -f ./philo/$(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
