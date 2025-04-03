/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 02:37:42 by marvin            #+#    #+#             */
/*   Updated: 2025/04/04 02:37:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/so_long.h"

void check_player_exit(t_map *map)
{
    int i = 0;
    int j;
    int player_count = 0;
    int exit_count = 0;

    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (map->grid[i][j] == 'p')
                player_count++;
            else if (map->grid[i][j] == 'e')
                exit_count++;
            j++;
        }
        i++;
    }
    if (player_count != 1)
    {
        write(1, "Map must contain exactly one player ('P')\n", 41);
        exit(1);
    }
    if (exit_count != 1)
    {
        write(1, "Map must contain exactly one exit ('E')\n", 40);
        exit(1);
    }
}

void check_collectibles(t_map *map)
{
    int i = 0;
    int j;
    int collectibles_count = 0;

    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (map->grid[i][j] == 'c')
                collectibles_count++;
            j++;
        }
        i++;
    }
    if (collectibles_count < 1)
    {
        write(1, "Map must contain at least one collectible ('C')\n", 46);
        exit(1);
    }
}

static int is_valid_char(char c)
{
    return (c == '1' || c == '0' || c == 'p' || c == 'e' || c == 'c');
}

void check_valid_characters(t_map *map)
{
    int i = 0;
    int j;

    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (!is_valid_char(map->grid[i][j]))
            {
                write(1, "Invalid character found in map\n", 31);
                exit(1);
            }
            j++;
        }
        i++;
    }
}
