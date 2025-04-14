/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_reachable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:36:50 by esir              #+#    #+#             */
/*   Updated: 2025/04/13 19:04:19 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	cleanup_collectibles(t_map *map)
{
	size_t	i;

	if (!map->collectibles)
		return ;
	i = 0;
	while ((int)i < map->collectible_count)
	{
		free(map->collectibles[i]);
		i++;
	}
	free(map->collectibles);
	map->collectibles = NULL;
}

static void	cleanup_map_grid(t_map *map)
{
	size_t	i;

	if (!map->grid)
		return ;
	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

static void	cleanup_map_clone(char **map_clone, size_t height)
{
	size_t	i;

	if (!map_clone)
		return ;
	i = 0;
	while (i < height)
	{
		free(map_clone[i]);
		i++;
	}
	free(map_clone);
}

void	exit_reachable(t_map *map, char **map_clone, const char *error_msg)
{
	cleanup_collectibles(map);
	cleanup_map_clone(map_clone, map->height);
	cleanup_map_grid(map);
	free(map);
	if (error_msg)
		write(1, error_msg, ft_strlen(error_msg));
	exit(1);
}
