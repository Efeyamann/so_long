/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_reachable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:59:06 by heret             #+#    #+#             */
/*   Updated: 2025/04/05 01:33:13 by heret            ###   ########.fr       */
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

static char	**get_flood_filled_map(t_map *map)
{
	char	**map_clone;
	int		size[2];

	map_clone = clone_map(map);
	if (!map_clone)
		return (NULL);

	size[0] = map->width;
	size[1] = map->height;

	flood_fill(map_clone, map->player_x, map->player_y, size);

	return (map_clone);
}

static void	check_exit_reachable(t_map *map)
{
	char	**map_clone;
	size_t	i;

	map_clone = get_flood_filled_map(map);
	if (!map_clone)
		return ;
	if (map_clone[map->exit_y][map->exit_x] != 'V')
	{
		write(1, "The exit is not reachable!\n", 27);
		exit(1);
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

	map_clone = get_flood_filled_map(map);
	if (!map_clone)
		return ;
	i = 0;
	while (i < (size_t)map->collectible_count)
	{
		col_x = map->collectibles[i][0];
		col_y = map->collectibles[i][1];
		if (map_clone[col_y][col_x] != 'V')
		{
			write(1, "A collectible is not reachable!\n", 32);
			exit(1);
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
