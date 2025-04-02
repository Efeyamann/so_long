/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:03:42 by esir              #+#    #+#             */
/*   Updated: 2025/01/25 08:46:16 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	formats(char type, va_list args, int *final_count)
{
	char	c;

	if (type == 'c')
	{
		c = (char)va_arg(args, int);
		ft_c(c, final_count);
	}
	else if (type == 's')
		ft_s(va_arg(args, char *), final_count);
	else if (type == 'p')
		ft_p(va_arg(args, void *), final_count);
	else if (type == 'd' || type == 'i')
		ft_di(va_arg(args, int), final_count);
	else if (type == 'u')
		ft_u(va_arg(args, unsigned int), final_count);
	else if (type == 'x')
		ft_x(va_arg(args, unsigned int), final_count);
	else if (type == 'X')
		ft_upperx(va_arg(args, unsigned int), final_count);
	else if (type == '%')
	{
		write(1, "%%", 1);
		*final_count += 1;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		final_count;

	i = 0;
	final_count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			formats(str[i], args, &final_count);
		}
		else
		{
			write(1, &str[i], 1);
			final_count += 1;
		}
		i++;
	}
	va_end(args);
	return (final_count);
}
