/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_and_ber_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:59:54 by heret             #+#    #+#             */
/*   Updated: 2025/04/04 19:17:04 by heret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "fcntl.h"
#include <unistd.h>

void	xpm_control0(void)
{
	int	fd_char;
	int	fd_exit;
	int	fd_background;


	fd_char = open("assets/char.xpm", O_RDWR);
	fd_exit = open("assets/exit.xpm", O_RDWR);
	fd_background = open("assets/background.xpm", O_RDWR);
	if (fd_char <= 0 || fd_exit <= 0 || fd_background <= 0)
	{
		write(1, "Missing assets!\n", 16);
		close(fd_char);
		close(fd_exit);
		close(fd_background);
		exit(1);
	}
	close(fd_char);
	close(fd_exit);
	close(fd_background);
}

void	xpm_control1(void)
{
	int	fd_collect;
	int	fd_wall;

	fd_collect = open("assets/collect.xpm", O_RDWR);
	fd_wall = open("assets/wall.xpm", O_RDWR);
	if (fd_collect <= 0 || fd_wall <= 0)
	{
		write(1, "Missing assets!\n", 16);
		close(fd_collect);
		close(fd_wall);
		exit(1);
	}
	close(fd_collect);
	close(fd_wall);
}

void	ber_control(char *path)
{
	int		len;

	len = ft_strlen(path);
	if (path[len - 1] != 'r' || path[len - 2] != 'e'
		|| path[len - 3] != 'b' || path[len - 4] != '.')
	{
		write(1, "File extension of map is wrong!\n", 32);
		exit(1);
	}
}

void	file_control(char *path)
{
	int		fd;

	fd = open(path, O_RDWR);
	if (fd <= 0)
	{
		write(1, "Wrong file path\n", 16);
		close(fd);
		exit(1);
	}
	close(fd);
}
