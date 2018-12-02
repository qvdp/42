FLAGS = -Wall -Wextra -Werror

NAME = libunit.a

SOURCES = loadtest.c sig_handler.c print.c

INCLUDES = ./inc/

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "\033[1;34mLibunit\t\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

%.o: %.c
	@gcc $(FLAGS) -I $(INCLUDES) -o $@ -c $?

clean:
	@rm -rf $(OBJECTS)
	@echo "\033[1;34mLibunit\t\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -fr $(NAME)
	@echo "\033[1;34mLibunit\t\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

debug: fclean
	gcc $(FLAGS) -I $(INCLUDE) -c $(SOURCES)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
