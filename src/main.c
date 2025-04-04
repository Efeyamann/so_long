/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:11:55 by heret             #+#    #+#             */
/*   Updated: 2025/04/04 19:18:50 by heret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map	*map;

	if (argc == 2)
	{
		xpm_control0();
		xpm_control1();
		ber_control(argv[1]);
		file_control(argv[1]);
		map = read_map(argv[1]);
		map_control(map);
	}
	return (0);
}
