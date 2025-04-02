/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cspdi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:33:25 by esir              #+#    #+#             */
/*   Updated: 2025/01/25 08:45:46 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_c(const char str, int *final_count)
{
	write(1, &str, 1);
	(*final_count) += 1;
}

void	ft_s(const char *str, int *final_count)
{
	int	a;

	a = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		*final_count += 6;
		return ;
	}
	while (str[a])
	{
		write(1, &str[a], 1);
		a++;
		(*final_count)++;
	}
}

void	ft_p(void *str, int *final_count)
{
	unsigned long	address;
	char			*hex;
	char			h[16];
	int				k;

	k = 0;
	hex = "0123456789abcdef";
	if (!str)
		return ((void)(write(1, "(nil)", 5) && (*final_count += 5)));
	address = (unsigned long)str;
	write(1, "0x", 2);
	*final_count += 2;
	while (address > 0)
	{
		h[k++] = hex[address % 16];
		address /= 16;
	}
	while (k--)
	{
		write(1, &h[k], 1);
		(*final_count)++;
	}
}

void	ft_di(int n, int *final_count)
{
	char	a;

	if (n == -2147483648)
	{
		write(1, "-2", 2);
		(*final_count) += 2;
		n = 147483648;
	}
	if (n < 0)
	{
		write (1, "-", 1);
		(*final_count) += 1;
		n = -n;
	}
	if (n >= 10)
		ft_di(n / 10, final_count);
	a = n % 10 + '0';
	write(1, &a, 1);
	(*final_count) += 1;
}
