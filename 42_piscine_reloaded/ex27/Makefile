# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:29:47 by qvan-der          #+#    #+#              #
#    Updated: 2018/11/07 15:17:06 by qvan-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEST = ft_display_file
FLAGS = -Wall -Werror -Wextra
SRCS = srcs/ft_display_file.c\
	  srcs/ft_putstr.c\
	  srcs/ft_putnbr.c\
	  srcs/ft_putchar.c
HEADER = includes/.
OUTPUT = ft_display_file.o\
	  ft_putstr.o\
	  ft_putnbr.o\
	  ft_putchar.o

all: make

make:
	gcc $(FLAGS) -o $(DEST) -I $(HEADER) $(SRCS)

clean:
	/bin/rm -f $(OUTPUT)

fclean:	clean
	/bin/rm -f $(DEST)

re: fclean all
