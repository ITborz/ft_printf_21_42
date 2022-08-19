/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:55:14 by bkristen          #+#    #+#             */
/*   Updated: 2022/01/04 18:03:17 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	ar;

	i = 0;
	len = 0;
	va_start(ar, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_format(str, i, ar);
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(ar);
	return (len);
}
