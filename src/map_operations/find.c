/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 01:16:09 by heret             #+#    #+#             */
/*   Updated: 2025/04/05 04:42:59 by heret            ###   ########.fr       */
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

void	find_collectiables(t_map *map)
{
	size_t	i;
	size_t	j;
	int		collectible_index;

	i = 0;
	collectible_index = 0;
	map->collectibles = malloc(sizeof(int *) * map->collectible_count);
	if (!map->collectibles)
		return ;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'C')
			{
				map->collectibles[collectible_index] = malloc(sizeof(int) * 2);
				map->collectibles[collectible_index][0] = j;
				map->collectibles[collectible_index][1] = i;
				collectible_index++;
			}
			j++;
		}
		i++;
	}
}
