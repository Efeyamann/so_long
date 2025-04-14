/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:12:56 by esir              #+#    #+#             */
/*   Updated: 2025/04/13 17:33:31 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **grid, int xy[2], int size[2], int allow_exit)
{
	int	x;
	int	y;
	int	next_xy[2];

	x = xy[0];
	y = xy[1];
	if (x < 0 || y < 0 || x >= size[0] || y >= size[1]
		|| grid[y][x] == '1' || grid[y][x] == 'V'
		|| (!allow_exit && grid[y][x] == 'E'))
		return ;
	grid[y][x] = 'V';
	next_xy[0] = x + 1;
	next_xy[1] = y;
	flood_fill(grid, next_xy, size, allow_exit);
	next_xy[0] = x - 1;
	next_xy[1] = y;
	flood_fill(grid, next_xy, size, allow_exit);
	next_xy[0] = x;
	next_xy[1] = y + 1;
	flood_fill(grid, next_xy, size, allow_exit);
	next_xy[0] = x;
	next_xy[1] = y - 1;
	flood_fill(grid, next_xy, size, allow_exit);
}

static int	handle_exit_collectibles(t_game *game, size_t new_x, size_t new_y)
{
	if (game->map->grid[new_y][new_x] == 'E')
	{
		if (game->map->collectible_count == 0)
		{
			ft_printf("You collected all items! Exiting...\n");
			ft_printf("Calling exit_game...\n");
			exit_game(game);
		}
		else
		{
			ft_printf("You need to collect all items first!\n");
			return (0);
		}
	}
	if (game->map->grid[new_y][new_x] == 'C')
	{
		game->map->collectible_count--;
	}
	return (1);
}

static void	move_p_logic(int key, t_game *game, size_t *new_x, size_t *new_y)
{
	size_t	x;
	size_t	y;

	x = game->map->player_x;
	y = game->map->player_y;
	*new_x = x;
	*new_y = y;
	if (key == KEY_W && y > 0 && game->map->grid[y - 1][x] != '1')
		(*new_y)--;
	else if (key == KEY_S && y < game->map->height - 1
		&& game->map->grid[y + 1][x] != '1')
		(*new_y)++;
	else if (key == KEY_A && x > 0 && game->map->grid[y][x - 1] != '1')
		(*new_x)--;
	else if (key == KEY_D && x < game->map->width - 1
		&& game->map->grid[y][x + 1] != '1')
		(*new_x)++;
}

int	move_player(int keycode, t_game *game)
{
	size_t	new_x;
	size_t	new_y;

	if (keycode == KEY_ESC)
		exit_game(game);
	move_p_logic(keycode, game, &new_x, &new_y);
	if ((int)new_x == game->map->player_x && (int)new_y == game->map->player_y)
		return (0);
	if (!handle_exit_collectibles(game, new_x, new_y))
		return (0);
	game->move_count++;
	ft_printf("Move count: %d\n", game->move_count);
	game->map->grid[game->map->player_y][game->map->player_x] = '0';
	game->map->player_x = new_x;
	game->map->player_y = new_y;
	game->map->grid[new_y][new_x] = 'P';
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
	return (0);
}
