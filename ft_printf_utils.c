/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 20:38:45 by bkristen          #+#    #+#             */
/*   Updated: 2022/01/04 18:14:26 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list ar)
{
	char	c;

	c = va_arg(ar, int);
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(va_list ar)
{
	char	*str;

	str = va_arg(ar, char *);
	if (str)
	{
		write(1, str, ft_strlen(str));
		return (ft_strlen(str));
	}
	write(1, "(null)", 6);
	return (6);
}

int	ft_hexadecimal(va_list ar)
{
	unsigned long	n;
	char			*p;

	p = "0123456789abcdef";
	n = va_arg(ar, unsigned long);
	if (n == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	else
		ft_itoa(n, p);
	return (ft_get_len(n) + 2);
}

int	ft_hexadecimal_x(va_list ar, const char c)
{
	unsigned int	n;
	char			*p;
	char			*p2;

	p = "0123456789ABCDEF";
	p2 = "0123456789abcdef";
	n = va_arg(ar, unsigned int);
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		if (c == 'x')
		{
			ft_itoa(n, p2);
			return (ft_get_len(n));
		}
	}
	ft_itoa(n, p);
	return (ft_get_len(n));
}

int	ft_format(const char *str, int i, va_list ar)
{
	int	j;

	j = 0;
	if (str[i] == 'c')
		j = ft_print_char(ar);
	else if (str[i] == 's')
		j = ft_print_str(ar);
	else if (str[i] == 'p')
	{
		write(1, "0x", 2);
		j = ft_hexadecimal(ar);
	}
	else if (str[i] == 'i' || str[i] == 'd')
		j = ft_decimal(ar);
	else if (str[i] == 'u')
		j = ft_decimal_u(ar);
	else if (str[i] == 'x' || str[i] == 'X')
		j = ft_hexadecimal_x(ar, str[i]);
	else if (str[i] == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (j);
}
