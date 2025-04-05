/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 01:55:10 by heret             #+#    #+#             */
/*   Updated: 2025/04/05 04:58:27 by heret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	move_player(int keycode, t_game *game)
{
	size_t	x;
	size_t	y;
	size_t	new_x;
	size_t	new_y;

	x = game->map->player_x;
	y = game->map->player_y;
	new_x = x;
	new_y = y;
	if (keycode == KEY_W && y > 0 && game->map->grid[y - 1][x] != '1')
		new_y--;
	else if (keycode == KEY_S && y < game->map->height - 1
		&& game->map->grid[y + 1][x] != '1')
		new_y++;
	else if (keycode == KEY_A && x > 0 && game->map->grid[y][x - 1] != '1')
		new_x--;
	else if (keycode == KEY_D && x < game->map->width - 1
		&& game->map->grid[y][x + 1] != '1')
		new_x++;
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
	game->map->grid[y][x] = '0';
	game->map->player_x = new_x;
	game->map->player_y = new_y;
	game->map->grid[new_y][new_x] = 'P';
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
	if (keycode == KEY_ESC)
		exit_game(game);
	return (0);
}

static void	render_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	size_t		x;
	size_t		y;
	char		tile;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			tile = game->map->grid[y][x];
			if (tile == '0' || tile == 'C' || tile == 'E' || tile == 'P')
				render_tile(game, game->img_floor, x, y);
			if (tile == '1')
				render_tile(game, game->img_wall, x, y);
			else if (tile == 'C')
				render_tile(game, game->img_collectible, x, y);
			else if (tile == 'E')
				render_tile(game, game->img_exit, x, y);
			x++;
		}
		y++;
	}
	render_tile(game, game->img_player, game->map->player_x,
		game->map->player_y);
}

void	init_game(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game);
	width = game->map->width * TILE_SIZE;
	height = game->map->height * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	game->img_player = mlx_xpm_file_to_image(game->mlx, "assets/char.xpm",
			&width, &height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm",
			&width, &height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "assets/background.xpm",
			&width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm",
			&width, &height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/collect.xpm", &width, &height);
	game->move_count = 0;
}
