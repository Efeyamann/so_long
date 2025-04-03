NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libs/libft
PRINTF_PATH = libs/ft_printf
MLX_PATH = libs/minilibx-linux

LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/libftprintf.a
MLX = libs/minilibx-linux/libmlx.a -lXext -lX11 -lm -lz

SRC = main.c
OBJ = $(SRC:.c=.o)

INCLUDES = -I includes -I $(MLX_PATH) -I $(LIBFT_PATH) -I $(PRINTF_PATH)

all: $(LIBFT) $(PRINTF) $(MLX) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLX) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(PRINTF):
	$(MAKE) -C $(PRINTF_PATH)

$(MLX):
	$(MAKE) -C $(MLX_PATH)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re $(LIBFT) $(PRINTF)


