/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 02:13:11 by marvin            #+#    #+#             */
/*   Updated: 2025/04/04 21:15:59 by heret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "unistd.h"

static void	check_rectangle(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->grid[i]) != map->width)
		{
			write(1, "Map is not a rectangle\n", 23);
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height)
		{
			if (map->grid[j][i] == '\0')
			{
				write(1, "Map is not a rectangle\n", 23);
				exit(1);
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
			write(1, "Map borders are not correctly set\n", 34);
			exit(1);
		}
		if (map->grid[i][last_col] != '1')
		{
			write(1, "Map borders are not correctly set\n", 34);
			exit(1);
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
			write(1, "Map borders are not correctly set\n", 34);
			exit(1);
		}
		i++;
	}
	i = 0;
	while (map->grid[last_row][i])
	{
		if (map->grid[last_row][i] != '1')
		{
			write(1, "Map borders are not correctly set\n", 34);
			exit(1);
		}
		i++;
	}
}

void	map_control(t_map *map)
{
	check_border_w(map);
	check_border_h(map);
	check_rectangle(map);
	check_valid_characters(map);
	check_exit(map);
	check_player(map);
	check_collectibles(map);
	find_exit(map);
	find_player(map);
	is_reachable(map);
}
