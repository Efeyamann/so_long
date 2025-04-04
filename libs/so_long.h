/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:58:35 by heret             #+#    #+#             */
/*   Updated: 2025/04/04 21:42:10 by heret            ###   ########.fr       */
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

# define MAX_MAP_SIZE 1024

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
	int		collected;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		collected;
	t_map	*map;
}	t_player;

typedef struct s_collectible
{
	int		x;
	int		y;
	bool	collected;
}	t_collectible;

typedef struct s_exit
{
	int		x;
	int		y;
	bool	is_open;
}	t_exit;

typedef struct s_game
{
	t_map			map;
	t_player		player;
	t_exit			exit;
	t_collectible	*collectibles;
}	t_game;

void	xpm_control0(void);
void	xpm_control1(void);
void	ber_control(char *path);
void	file_control(char *path);
t_map	*read_map(char *filename);
void	map_control(t_map *map);
void	check_valid_characters(t_map *map);
void	check_player(t_map *map);
void	check_exit(t_map *map);
void	check_collectibles(t_map *map);
void	find_exit(t_map *map);
void	find_player(t_map *map);
void	is_reachable(t_map *map);

#endif