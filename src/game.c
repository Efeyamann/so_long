/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 01:55:10 by heret             #+#    #+#             */
/*   Updated: 2025/04/12 16:13:12 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
