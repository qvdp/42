# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:29:47 by qvan-der          #+#    #+#              #
#    Updated: 2018/11/06 17:29:49 by qvan-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEST = libft.a
FLAGS = -Wall -Werror -Wextra
SRCS = srcs/ft_putchar.c\
	  srcs/ft_putstr.c\
	  srcs/ft_strcmp.c\
	  srcs/ft_strlen.c \
	  srcs/ft_swap.c
HEADER = includes/.
OUTPUT = ft_putchar.o\
		 ft_putstr.o\
		 ft_strcmp.o\
		 ft_strlen.o\
		 ft_swap.o

all: make

make:
	gcc $(FLAGS) -I $(HEADER) -c $(SRCS)
	ar rc $(DEST) $(OUTPUT)
	ranlib $(DEST)

clean:
	/bin/rm -f $(OUTPUT)

fclean:	clean
	/bin/rm -f $(DEST)

re: fclean all
