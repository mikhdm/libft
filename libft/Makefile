# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 15:42:51 by rmander           #+#    #+#              #
#    Updated: 2021/10/10 17:09:13 by rmander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror -Ofast -MMD
NAME = libft.a
INCLUDE = ./ 

SRCS = ./memory/ft_memset.c \
	   ./memory/ft_bzero.c \
	   ./memory/ft_memcpy.c \
	   ./memory/ft_memccpy.c \
	   ./memory/ft_memmove.c \
	   ./memory/ft_memchr.c \
	   ./memory/ft_memcmp.c \
	   ./string/ft_strlen.c \
	   ./string/ft_strlcpy.c \
	   ./string/ft_strlcat.c \
	   ./string/ft_strchr.c \
	   ./string/ft_strrchr.c \
	   ./string/ft_strnstr.c \
	   ./string/ft_strcmp.c \
	   ./string/ft_strncmp.c \
	   ./string/ft_toupper.c \
	   ./string/ft_tolower.c \
	   ./string/ft_strdup.c \
	   ./string/ft_substr.c \
	   ./string/ft_strjoin.c \
	   ./string/ft_strtrim.c \
	   ./string/ft_split.c \
	   ./string/ft_split_any.c \
	   ./string/ft_splitf.c \
	   ./string/ft_strslen.c \
	   ./string/ft_strsfree.c \
	   ./string/ft_strupper.c \
	   ./string/ft_strlower.c \
	   ./string/ft_strmapi.c \
	   ./string/ft_strlen_until.c \
	   ./string/ft_strdup_until.c \
	   ./std/ft_atoi.c \
	   ./std/ft_min.c \
	   ./std/ft_max.c \
	   ./is/ft_isalpha.c \
	   ./is/ft_isdigit.c \
	   ./is/ft_isalnum.c \
	   ./is/ft_isascii.c \
	   ./is/ft_isprint.c \
	   ./is/ft_isspace.c \
	   ./std/ft_calloc.c \
	   ./std/ft_itoa.c \
	   ./io/ft_putchar_fd.c \
	   ./io/ft_putstr_fd.c \
	   ./io/ft_putendl_fd.c \
	   ./io/ft_putnbr_fd.c \
	   ./io/get_next_line/get_next_line.c \
	   ./io/get_next_line/get_next_line_utils.c

BONUSRCS = ./list/ft_lstnew.c \
		   ./list/ft_lstadd_front.c \
		   ./list/ft_lstsize.c \
		   ./list/ft_lstlast.c \
		   ./list/ft_lstadd_back.c \
		   ./list/ft_lstdelone.c \
		   ./list/ft_lstclear.c \
		   ./list/ft_lstiter.c \
		   ./list/ft_lstmap.c

OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUSRCS:.c=.o)

DEPFILES = $(SRCS:.c=.d)
BONUSDEPFILES = $(BONUSRCS:.c=.d)

ifeq ($(MAKECMDGOALS), bonus)
DEPS = $(OBJS) $(BONUSOBJS)
else
DEPS = $(OBJS)
endif

all: $(NAME)

bonus: $(NAME)

$(NAME): $(DEPS)
	ar rcs $@ $^

-include $(DEPFILES) $(BONUSDEPFILES)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

clean:
	rm -f $(OBJS)
	rm -f $(BONUSOBJS)
	rm -f $(DEPFILES)
	rm -f $(BONUSDEPFILES)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re bonus