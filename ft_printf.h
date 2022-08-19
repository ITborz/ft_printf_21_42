/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 20:14:25 by bkristen          #+#    #+#             */
/*   Updated: 2022/01/04 18:03:57 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int			ft_format(const char *str, int i, va_list ar);
int			ft_printf(const char *str, ...);
size_t		ft_strlen(const char *str);
int			ft_get_len(unsigned long n);
void		ft_itoa(unsigned long n, char *p);
int			ft_itoa_d(int n);
int			ft_itoa_u(unsigned int n);
int			ft_decimal(va_list ar);
int			ft_decimal_u(va_list ar);
int			ft_print_char(va_list ar);
int			ft_print_str(va_list ar);
int			ft_hexadecimal(va_list ar);
int			ft_hexadecimal_x(va_list ar, const char c);

#endif