/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uxX.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:51:31 by esir              #+#    #+#             */
/*   Updated: 2025/01/06 09:13:58 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_u(unsigned int n, int *final_count)
{
	char	b;

	if (n >= 10)
		ft_u(n / 10, final_count);
	b = n % 10 + '0';
	write(1, &b, 1);
	(*final_count) += 1;
}

void	ft_x(unsigned int n, int *final_count)
{
	char	*lower_hexa;
	char	c;

	lower_hexa = "0123456789abcdef";
	if (n >= 16)
		ft_x(n / 16, final_count);
	c = lower_hexa[n % 16];
	write(1, &c, 1);
	(*final_count) += 1;
}

void	ft_upperx(unsigned int n, int *final_count)
{
	char	*upper_hexa;
	char	d;

	upper_hexa = "0123456789ABCDEF";
	if (n >= 16)
		ft_upperx(n / 16, final_count);
	d = upper_hexa[n % 16];
	write(1, &d, 1);
	(*final_count) += 1;
}
