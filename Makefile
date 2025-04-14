NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libs/libft
PRINTF_PATH = libs/ft_printf
MLX_PATH = libs/minilibx-linux
GNL_PATH = libs/get_next_line

LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/libftprintf.a
MLX = $(MLX_PATH)/libmlx.a -lXext -lX11 -lm -lz

SRC_DIR = src
MAP_OPERATIONS_DIR = $(SRC_DIR)/map_operations

SRC =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/game.c \
		$(SRC_DIR)/exit_game.c \
		$(SRC_DIR)/move.c \
		$(MAP_OPERATIONS_DIR)/map_control.c \
		$(MAP_OPERATIONS_DIR)/exit_with_cleanup.c \
		$(MAP_OPERATIONS_DIR)/exit_reachable.c \
		$(MAP_OPERATIONS_DIR)/find.c \
		$(MAP_OPERATIONS_DIR)/check.c \
		$(MAP_OPERATIONS_DIR)/read_map.c \
		$(MAP_OPERATIONS_DIR)/read_map_utils.c \
		$(MAP_OPERATIONS_DIR)/xpm_and_ber_check.c \
		$(MAP_OPERATIONS_DIR)/is_reachable.c

GNL_SRC = $(GNL_PATH)/get_next_line.c $(GNL_PATH)/get_next_line_utils.c
GNL_OBJ = $(GNL_SRC:.c=.o)

OBJ = $(SRC:.c=.o) $(GNL_OBJ)

INCLUDES = -I libs -I $(MLX_PATH) -I $(LIBFT_PATH) -I $(PRINTF_PATH) -I $(GNL_PATH)

all: $(LIBFT) $(PRINTF) $(MLX) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLX) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH) all

$(PRINTF):
	$(MAKE) -C $(PRINTF_PATH) all

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

.PHONY: all clean fclean re