# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 21:28:43 by qvan-der          #+#    #+#              #
#    Updated: 2018/12/02 21:28:50 by qvan-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tester

SRC = tests/00_launcher.c\
			tests/01_test_bus.c\
			tests/02_test_segv.c\
			tests/03_test_ko.c\
			tests/04_test_ok.c\
			main.c\

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

FW_PATH = ./../framework/

FW_PATH_INC = ./../framework/inc/

LFT_PATH = ./../libft/

FW_LIB = $(FW_PATH)libunit.a

LFT_LIB = $(LFT_PATH)libft.a

LFT_PATH_INC = ./../libft/inc/

all: $(NAME)
	@(cd $(FW_PATH) && make)
	@(cd $(LFT_PATH) && make)

$(NAME): $(OBJ)
	@(cd $(FW_PATH) && make)
	@(cd $(LFT_PATH) && make)
	@gcc $(FLAGS) $^ -o $@  -L $(LFT_PATH) -lft -L $(FW_PATH) -lunit
	@echo "\033[1;34mLib test\t\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $?

clean:
	@rm -rf $(OBJ)
	@echo "\033[1;34mLib test\t\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[1;34mLib test\t\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

test: all execute

execute:
	./$(NAME)
.PHONY: re clean fclean all
