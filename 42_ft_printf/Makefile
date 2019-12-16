CC = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = srcs

DIR_O = temp

HEADER = includes

SOURCES = ft_printf.c \
		ft_parser.c \
		ft_integer.c \
		ft_address.c \
		ft_char.c \
		ft_string.c \
		main.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Printf\t\tCompilation\t[OK]"

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temp
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)
	@echo "Printf\t\tCleaning obj.\t[OK]"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "Printf\t\tCleaning lib.\t[OK]"

re: fclean all
