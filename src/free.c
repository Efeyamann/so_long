/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 04:46:40 by heret             #+#    #+#             */
/*   Updated: 2025/04/05 05:07:09 by heret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		i = 0;
		while ((int)i < game->map->collectible_count)
		{
			free(game->map->collectibles[i]);
			game->map->collectibles[i] = NULL;
			i++;
		}
		free(game->map->collectibles);
		game->map->collectibles = NULL;
		free(game->map);
		game->map = NULL;
	}
}

static void	free_game2(t_game *game)
{
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player && game->img_player)
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
	ft_printf("Entered exit_game function\n");
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
