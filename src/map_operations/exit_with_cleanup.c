/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_cleanup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:13:41 by esir              #+#    #+#             */
/*   Updated: 2025/04/13 18:51:22 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(t_map *map)
{
	size_t	i;

	if (!map || !map->grid)
		return ;
	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
	free(map);
}

void	exit_with_cleanup(t_map *map, const char *error_msg)
{
	if (error_msg)
		write(1, error_msg, ft_strlen(error_msg));
	free_map(map);
	exit(1);
}
