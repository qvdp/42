# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 14:10:10 by qvan-der          #+#    #+#              #
#    Updated: 2018/12/02 14:10:13 by qvan-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = libunit.a

SOURCES = loadtest.c sig_handler.c print.c

INCLUDES = ./inc/

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "\033[1;34mFramework\t\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

%.o: %.c
	@gcc $(FLAGS) -I $(INCLUDES) -o $@ -c $?

clean:
	@rm -rf $(OBJECTS)
	@echo "\033[1;34mFramework\t\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -fr $(NAME)
	@echo "\033[1;34mFramework\t\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

.PHONY: re clean fclean all
