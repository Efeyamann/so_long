/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:11:17 by esir              #+#    #+#             */
/*   Updated: 2025/04/13 15:12:11 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map(t_map *map, int line_count)
{
	map->grid[line_count] = NULL;
	map->height = line_count;
	if (line_count > 0)
		map->width = ft_strlen(map->grid[0]);
	else
		map->width = 0;
	map->collectible_count = 0;
	map->collected = 0;
	map->player_x = -1;
	map->player_y = -1;
	map->exit_x = -1;
	map->exit_y = -1;
}

char	*trim_newline(char *line)
{
	char	*newline;

	newline = ft_strchr(line, '\n');
	if (newline)
		*newline = '\0';
	return (line);
}
