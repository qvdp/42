NAME = tester

SRC = ft_atoi/00_launcher.c\
			ft_atoi/01_test_atoi_basic.c\
			ft_atoi/02_test_atoi_basic2.c\
			ft_atoi/03_test_atoi_basic3.c\
			ft_atoi/04_test_atoi_basic4.c\
			ft_atoi/05_test_atoi_basic5.c\
			ft_atoi/06_test_atoi_basic6.c\
			ft_atoi/07_test_atoi_basic7.c\
			ft_atoi/08_test_atoi_negativ.c\
			ft_atoi/09_test_atoi_letter.c\
			ft_atoi/10_test_atoi_letters.c\
			ft_atoi/11_test_atoi_null.c\
			ft_memcpy/00_launcher.c\
			ft_memcpy/01_test_memcpy_basic1.c\
			ft_memcpy/02_test_memcpy_basic2.c\
			ft_strcat/00_launcher.c\
			ft_strcat/01_test_strcat_basic1.c\
			ft_strcat/02_test_strcat_basic2.c\
			ft_strcat/03_test_strcat_basic3.c\
			ft_strcat/04_test_strcat_basic4.c\
			ft_strcat/05_test_strcat_basic5.c\
			ft_strcat/06_test_strcat_basic6.c\
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

test: all
	./$(NAME)

.PHONY: test re clean fclean all
