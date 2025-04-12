/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 04:46:40 by heret             #+#    #+#             */
/*   Updated: 2025/04/12 17:07:35 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_collectibles(t_map *map)
{
	size_t	i;

	if (map->collectibles != NULL)
	{
		i = 0;
		while ((int)i < map->original_collectible_count)
		{
			free(map->collectibles[i]);
			map->collectibles[i] = NULL;
			i++;
		}
		free(map->collectibles);
		map->collectibles = NULL;
	}
}

static void	free_game1(t_game *game)
{
	size_t	i;

	if (game->map != NULL)
	{
		i = 0;
		while (i < game->map->height)
		{
			free(game->map->grid[i]);
			game->map->grid[i] = NULL;
			i++;
		}
		free(game->map->grid);
		game->map->grid = NULL;
		if (game->map->collectibles != NULL)
		{
			free_collectibles(game->map);
		}
		free(game->map);
		game->map = NULL;
	}
}

static void	free_game2(t_game *game)
{
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
}

static void	free_game3(t_game *game)
{
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

void	exit_game(t_game *game)
{
	if (game == NULL)
		return ;
	free_game1(game);
	free_game2(game);
	free_game3(game);
	if (game->mlx != NULL)
	{
		mlx_loop_end(game->mlx);
	}
	exit(1);
}
