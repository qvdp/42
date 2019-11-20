CC = gcc

NAME = fdf

FLAGS = -Wall -Wextra -Werror

LIBFT = libft
LIBFT_LNK	= -l ft

LIBMLX = libmlx
LIBMLX_LNK	= -l mlx -framework OpenGL -framework AppKit

DIR_S = srcs

DIR_O = .temp

SRC = main.c \
			ft_check.c \
			ft_build_map.c \
			ft_init_cam.c \
			ft_fdf.c \
			ft_event_listener.c \
			ft_create_image.c \
			ft_draw.c

OBJ	= $(addprefix $(DIR_O)/,$(SRC:.c=.o))

HEADERS	= includes

all: $(NAME)

$(DIR_O)/%.o:$(DIR_S)/%.c
	mkdir -p $(DIR_O)
	$(CC) $(FLAGS) -I $(LIBMLX) -I $(LIBFT) -I $(HEADERS) -o $@ -c $<

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@make -C $(LIBMLX)
	$(CC) $(OBJ) -L $(LIBMLX) $(LIBMLX_LNK) -L $(LIBFT) $(LIBFT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(DIR_O)
	make -C $(LIBFT) clean
	make -C $(LIBMLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
