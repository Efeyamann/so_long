/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:58:35 by heret             #+#    #+#             */
/*   Updated: 2025/04/05 01:32:58 by heret            ###   ########.fr       */
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
	int		**collectibles;
}	t_map;

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
void	find_collectiables(t_map *map);
void	is_reachable(t_map *map);
void	flood_fill(char **grid, int x, int y, int size[2]);

#endif