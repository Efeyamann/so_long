/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:11:55 by heret             #+#    #+#             */
/*   Updated: 2025/04/05 04:58:57 by heret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc == 2)
	{
		xpm_control0();
		xpm_control1();
		ber_control(argv[1]);
		file_control(argv[1]);
		game.map = read_map(argv[1]);
		map_control(game.map);
		init_game(&game);
		render_map(&game);
		mlx_key_hook(game.win, move_player, &game);
		mlx_hook(game.win, 17, 0, close_window, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
