# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 17:40:21 by fgalvez-          #+#    #+#              #
#    Updated: 2024/06/20 16:06:38 by fgalvez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS =-Wall -Wextra -Werror

INCLUDE = ft_printf.h

SRCES = ft_printf.c \
	formatos.c \
	formatos_numéricos.c

OBJS = $(SRCES:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	ar -crs $(NAME) $(OBJS)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

