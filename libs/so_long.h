/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:58:35 by heret             #+#    #+#             */
/*   Updated: 2025/04/03 14:25:02 by heret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/minilibx-linux/mlx.h"
# include "libs/ft_printf/ft_printf.h"
# include "libs/get_next_line/get_next_line.h"
# include "libs/libft/libft.h"
# include "stdbool.h"

#define MAX_MAP_SIZE 1024

typedef struct s_map
{
    char    **grid;
    int     width;
    int     height;
    int     player_x;
    int     player_y;
    int     exit_x;
    int     exit_y;
    int     collectible_count;
    int     collected;
} t_map;

typedef struct s_player
{
    int x;
    int y;
    int collected;
    t_map *map;
} t_player;

typedef struct s_collectible
{
    int x;
    int y;
    bool collected;
} t_collectible;

typedef struct s_exit
{
    int x;
    int y;
    bool is_open;
} t_exit;

typedef struct s_game
{
    t_map          map;
    t_player       player;
    t_exit         exit;
    t_collectible  *collectibles;
} t_game;

void	xpm_control0(void);
void	xpm_control1(void);
void	ber_control(char *path);
void	file_control(char *path);
char    *read_map(char *filename);
void    map_control(t_map *map);
void    check_valid_characters(t_map *map);
void    check_player_exit(t_map *map);
void    check_collectibles(t_map *map);

#endif