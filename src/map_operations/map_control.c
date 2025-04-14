/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 02:13:11 by marvin            #+#    #+#             */
/*   Updated: 2025/04/13 18:57:52 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "unistd.h"

static void	check_row_lengths(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->grid[i]) != map->width)
		{
			exit_with_cleanup(map, "Map is not a rectangle\n");
		}
		i++;
	}
}

static void	check_column_lengths(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height)
		{
			if (map->grid[j][i] == '\0')
			{
				exit_with_cleanup(map, "Map is not a rectangle\n");
			}
			j++;
		}
		i++;
	}
}

static void	check_border_w(t_map *map)
{
	size_t	i;
	int		last_col;

	last_col = map->width - 1;
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1')
		{
			exit_with_cleanup(map, "Map borders are not correctly set\n");
		}
		if (map->grid[i][last_col] != '1')
		{
			exit_with_cleanup(map, "Map borders are not correctly set\n");
		}
		i++;
	}
}

static void	check_border_h(t_map *map)
{
	int	i;
	int	last_row;

	last_row = map->height - 1;
	i = 0;
	while (map->grid[0][i])
	{
		if (map->grid[0][i] != '1')
		{
			exit_with_cleanup(map, "Map borders are not correctly set\n");
		}
		i++;
	}
	i = 0;
	while (map->grid[last_row][i])
	{
		if (map->grid[last_row][i] != '1')
		{
			exit_with_cleanup(map, "Map borders are not correctly set\n");
		}
		i++;
	}
}

void	map_control(t_map *map)
{
	check_border_w(map);
	check_border_h(map);
	check_row_lengths(map);
	check_column_lengths(map);
	check_valid_characters(map);
	check_exit(map);
	check_player(map);
	check_collectibles(map);
	find_exit(map);
	find_player(map);
	find_collectiables(map);
	is_reachable(map);
}
