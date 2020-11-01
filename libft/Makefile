# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 20:23:55 by rmander           #+#    #+#              #
#    Updated: 2020/11/01 20:27:07 by rmander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDE = libft.h

all: $(NAME)
	# TODO

%.o: %.c $(INCLUDE)
	gcc -o $@ -c $<

clean:
	rm -r *.o

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
