# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 17:40:21 by fgalvez-          #+#    #+#              #
#    Updated: 2024/04/25 17:40:21 by fgalvez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS =-Wall -Wextra -Werror
SRCES = ft_printf.c\
		formatos.c
OBJS = $(SRCES:.c=.o)

NAME = libftprintf.a

ft_printf: $(OBJS)
	$(CC) $(CFLAGS) -o ft_printf $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) ft_printf
