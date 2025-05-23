/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 02:37:42 by marvin            #+#    #+#             */
/*   Updated: 2025/04/13 18:24:04 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_player(t_map *map)
{
	size_t	i;
	size_t	j;
	int		player_count;

	i = 0;
	player_count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'P')
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
	{
		exit_with_cleanup(map, "Map must contain exactly one player ('P')\n");
	}
}

void	check_exit(t_map *map)
{
	size_t	i;
	size_t	j;
	int		exit_count;

	i = 0;
	exit_count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	if (exit_count != 1)
	{
		exit_with_cleanup(map, "Map must contain exactly one exit ('E')\n");
	}
}

void	check_collectibles(t_map *map)
{
	size_t	i;
	size_t	j;
	int		collectibles_count;

	i = 0;
	collectibles_count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'C')
				collectibles_count++;
			j++;
		}
		i++;
	}
	if (collectibles_count < 1)
	{
		exit_with_cleanup(map, "Map must have at least one collectible('C')\n");
	}
	map->collectible_count = collectibles_count;
}

static int	is_valid_char(char c)
{
	return (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C');
}

void	check_valid_characters(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (!is_valid_char(map->grid[i][j]))
			{
				exit_with_cleanup(map, "Invalid character found in map\n");
			}
			j++;
		}
		i++;
	}
}
