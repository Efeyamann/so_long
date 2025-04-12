/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:50:06 by marvin            #+#    #+#             */
/*   Updated: 2025/04/12 16:16:50 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "fcntl.h"

void	flood_fill(char **grid, int x, int y, int size[2])
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

static void	set_map(t_map *map, int line_count)
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

static char	*trim_newline(char *line)
{
	char	*newline;

	newline = ft_strchr(line, '\n');
	if (newline)
		*newline = '\0';
	return (line);
}

t_map	*read_map(char *filename)
{
	t_map	*map;
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	map = malloc(sizeof(t_map));
	if (!map || fd < 0)
		return (NULL);
	map->grid = malloc(sizeof(char *) * (MAX_MAP_SIZE + 1));
	if (!map->grid)
		return (free(map), NULL);
	while (i < MAX_MAP_SIZE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->grid[i] = trim_newline(line);
		i++;
	}
	set_map(map, i);
	close(fd);
	return (map);
}
