/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_reachable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:59:06 by heret             #+#    #+#             */
/*   Updated: 2025/04/13 18:55:19 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**clone_map(t_map *map)
{
	char		**map_clone;
	size_t		i;

	i = 0;
	map_clone = malloc(map->height * sizeof(char *));
	if (!map_clone)
		return (NULL);
	while (i < map->height)
	{
		map_clone[i] = ft_strdup(map->grid[i]);
		if (!map_clone[i])
		{
			while ((int)i >= 0)
				free(map_clone[--i]);
			free(map_clone);
			return (NULL);
		}
		i++;
	}
	return (map_clone);
}

static char	**get_flood_filled_map(t_map *map, int allow_exit)
{
	char	**map_clone;
	int		size[2];
	int		xy[2];

	map_clone = clone_map(map);
	if (!map_clone)
		return (NULL);
	xy[0] = map->player_x;
	xy[1] = map->player_y;
	size[0] = map->width;
	size[1] = map->height;
	flood_fill(map_clone, xy, size, allow_exit);
	return (map_clone);
}

static void	check_exit_reachable(t_map *map)
{
	char	**map_clone;
	size_t	i;

	map_clone = get_flood_filled_map(map, 1);
	if (!map_clone)
		return ;
	if (map_clone[map->exit_y][map->exit_x] != 'V')
	{
		exit_reachable(map, map_clone, "There has to be exit\n");
	}
	i = 0;
	while (i < map->height)
		free(map_clone[i++]);
	free(map_clone);
}

static void	check_collectibles_reachable(t_map *map)
{
	char	**map_clone;
	size_t	i;
	int		col_x;
	int		col_y;

	map_clone = get_flood_filled_map(map, 0);
	if (!map_clone)
		return ;
	i = 0;
	while (i < (size_t)map->collectible_count)
	{
		col_x = map->collectibles[i][0];
		col_y = map->collectibles[i][1];
		if (map_clone[col_y][col_x] != 'V')
		{
			exit_reachable(map, map_clone, "There has to be collectible\n");
		}
		i++;
	}
	i = 0;
	while (i < map->height)
		free(map_clone[i++]);
	free(map_clone);
}

void	is_reachable(t_map *map)
{
	check_exit_reachable(map);
	check_collectibles_reachable(map);
}
