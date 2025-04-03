/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 02:13:11 by marvin            #+#    #+#             */
/*   Updated: 2025/04/04 02:13:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/so_long.h"
#include "unistd.h"

static void     check_rectangle(t_map *map)
{
    int i;

    i = 0;
    while (i < map->height)
    {
        if (ft_strlen(map->grid[i]) != map->width)
        {
            write(1, "Map is not a rectangle: Row lengths are inconsistent\n", 55);
            exit(1);
        }
        i++;
    }
    i = 0;
    while (i < map->width)
    {
        int j = 0;
        while (j < map->height)
        {
            if (map->grid[j][i] == '\0')
            {
                write(1, "Map is not a rectangle: Columns are inconsistent\n", 53);
                exit(1);
            }
            j++;
        }
        i++;
    }
}

static void    check_border_w(t_map *map)
{
    int i;
    int last_w;

    last_w = map->height;
    i = 0;
    while (map->grid[i][0])
    {
        if (map->grid[i][0] != '1')
        {
            write(1, "Map borders are not correctly set\n", 34);
            exit(1);
        }
        i++;
    }
    i = 0;
    while (map->grid[i][last_w - 1])
    {
        if (map->grid[i][last_w - 1] != '1')
        {
            write(1, "Map borders are not correctly set\n", 34);
            exit(1);
        }
        i++;
    }
}

static void    check_border_h(t_map *map)
{
    int i;
    int last_h;

    last_h = map->width;
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
    while (map->grid[last_h - 1][i])
    {
        if (map->grid[last_h - 1][i] != '1')
        {
            write(1, "Map borders are not correctly set\n", 34);
            exit(1);
        }
        i++;
    }
}

void    map_control(t_map *map)
{
    check_border_w(map);
    check_border_h(map);
    check_rectangle(map);
    check_valid_characters(map);
    check_player_exit(map);
    check_collectibles(map); 
}