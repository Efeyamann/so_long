/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:58:35 by heret             #+#    #+#             */
/*   Updated: 2025/04/13 15:12:20 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "stdbool.h"
# include "stdio.h"

# define TILE_SIZE 32
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_map
{
	char	**grid;
	size_t	width;
	size_t	height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		collectible_count;
	int		original_collectible_count;
	int		collected;
	int		**collectibles;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	int		move_count;
	void	*img_player;
	void	*img_wall;
	void	*img_floor;
	void	*img_exit;
	void	*img_collectible;
}	t_game;

t_map	*read_map(char *filename);
void	xpm_control0(void);
void	xpm_control1(void);
void	ber_control(char *path);
void	file_control(char *path);
void	map_control(t_map *map);
void	free_map_resources(t_map *map, int i);
void	check_valid_characters(t_map *map);
void	check_player(t_map *map);
void	check_exit(t_map *map);
void	check_collectibles(t_map *map);
void	set_map(t_map *map, int line_count);
void	find_exit(t_map *map);
void	find_player(t_map *map);
void	find_collectiables(t_map *map);
void	is_reachable(t_map *map);
void	flood_fill(char **grid, int x, int y, int size[2]);
void	init_game(t_game *game);
void	render_map(t_game *game);
int		move_player(int keycode, t_game *game);
int		close_window(t_game *game);
void	exit_game(t_game *game);
char	*trim_newline(char *line);

#endif