# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 20:23:55 by rmander           #+#    #+#              #
#    Updated: 2020/11/04 00:32:05 by rmander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a
INCLUDE = libft.h
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	# TODO

$(NAME): $(OBJS)
	ar rcs $^

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	rm -r *.o

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
