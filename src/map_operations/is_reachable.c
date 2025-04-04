/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_reachable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:59:06 by heret             #+#    #+#             */
/*   Updated: 2025/04/04 21:55:27 by heret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_exit(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'E')
			{
				map->exit_x = j;
				map->exit_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	find_player(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'P')
			{
				map->player_x = j;
				map->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	flood_fill(char **grid, int x, int y, int size[2])
{
	if (x < 0 || y < 0 || x >= size[0] || y >= size[1]
		|| grid[y][x] == '1' || grid[y][x] == 'V')
		return ;
	grid[y][x] = 'V';
	flood_fill(grid, x + 1, y, size);
	flood_fill(grid, x - 1, y, size);
	flood_fill(grid, x, y + 1, size);
	flood_fill(grid, x, y - 1, size);
}

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

void	is_reachable(t_map *map)
{
	char	**map_clone;
	int		size[2];
	size_t	i;

	map_clone = clone_map(map);
	if (!map_clone)
		return ;
	size[0] = map->width;
	size[1] = map->height;
	flood_fill(map_clone, map->player_x, map->player_y, size);
	if (map_clone[map->exit_y][map->exit_x] != 'V')
	{
		i = 0;
		while (i < map->height)
			free(map_clone[i++]);
		free(map_clone);
		write(1, "The exit is not reachable!\n", 27);
		exit(1);
	}
	i = 0;
	while (i < map->height)
		free(map_clone[i++]);
	free(map_clone);
}
