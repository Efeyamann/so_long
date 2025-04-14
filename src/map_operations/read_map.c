/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:50:06 by marvin            #+#    #+#             */
/*   Updated: 2025/04/13 16:58:19 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "fcntl.h"

static int	open_file(char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		return (0);
	return (1);
}

static t_map	*allocate_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = malloc(sizeof(char *) * 8);
	if (!map->grid)
	{
		free(map);
		return (NULL);
	}
	return (map);
}

static char	**resize_grid(char **old_grid, int old_size, int new_size)
{
	char	**new_grid;
	int		i;

	new_grid = malloc(sizeof(char *) * new_size);
	if (!new_grid)
	{
		i = 0;
		while (i < old_size)
		{
			free(old_grid[i]);
			i++;
		}
		free(old_grid);
		return (NULL);
	}
	i = 0;
	while (i < old_size)
	{
		new_grid[i] = old_grid[i];
		i++;
	}
	free(old_grid);
	return (new_grid);
}

static int	read_and_store_lines(int fd, t_map *map, int *i, int *capacity)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*i >= *capacity)
		{
			*capacity *= 2;
			map->grid = resize_grid(map->grid, *i, *capacity);
			if (!map->grid)
				return (0);
		}
		map->grid[(*i)++] = trim_newline(line);
		line = get_next_line(fd);
	}
	map->grid[*i] = NULL;
	return (1);
}

t_map	*read_map(char *filename)
{
	t_map	*map;
	int		fd;
	int		capacity;
	int		i;

	capacity = 8;
	i = 0;
	if (!open_file(filename, &fd))
		return (NULL);
	map = allocate_map();
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	if (!read_and_store_lines(fd, map, &i, &capacity))
	{
		free_map_resources(map, i);
		close(fd);
		return (NULL);
	}
	set_map(map, i);
	close(fd);
	return (map);
}
