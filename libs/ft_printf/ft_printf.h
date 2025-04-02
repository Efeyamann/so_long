/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:21:28 by esir              #+#    #+#             */
/*   Updated: 2025/01/25 08:25:03 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_c(const char str, int *final_count);
void	ft_s(const char *str, int *final_count);
void	ft_p(void *str, int *final_count);
void	ft_di(int num, int *final_count);
void	ft_u(unsigned int n, int *final_count);
void	ft_x(unsigned int n, int *final_count);
void	ft_upperx(unsigned int n, int *final_count);

#endif