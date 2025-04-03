/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heret <heret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:11:55 by heret             #+#    #+#             */
/*   Updated: 2025/04/03 14:22:26 by heret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/so_long.h"

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		xpm_control0();
		xpm_control1();
		ber_control(argv[1]);
		file_control(argv[1]);
	}
	return (0);
}
