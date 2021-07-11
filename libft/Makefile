# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: troxanna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 19:33:07 by troxanna          #+#    #+#              #
#    Updated: 2020/11/19 20:51:36 by troxanna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I.

FUNC = 	ft_bzero.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strchr.c \
		ft_strnstr.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_isascii.c ft_calloc.c \
		ft_strdup.c ft_strrchr.c ft_strncmp.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_putchar_fd.c ft_itoa.c ft_split.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_strlcat.c ft_strmapi.c

BONUS_F = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		  ft_lstmap.c

BONUS_O = $(BONUS_F:.c=.o)

OBJ = $(FUNC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(OBJ) $(BONUS_O)
	ar rc $(NAME) $(OBJ) $(BONUS_O)
	ranlib $(NAME)

clean:
	rm -f $(OBJ) $(BONUS_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
