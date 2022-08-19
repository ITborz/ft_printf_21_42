/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:33:48 by bkristen          #+#    #+#             */
/*   Updated: 2022/01/04 18:09:46 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index])
	{
		dest [index] = src [index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

static int	ft_get_len_d(int n)
{
	int	size_n;
	int	nb;

	nb = n;
	size_n = 0;
	if (nb <= 0)
		size_n++;
	while (nb)
	{
		size_n++;
		nb /= 10;
	}
	return (size_n);
}

int	ft_itoa_d(int n)
{
	int		size_n;
	char	result_str[12];

	size_n = ft_get_len_d(n);
	result_str[size_n] = '\0';
	if (n == -2147483648)
		return (write(1, ft_strcpy(result_str, "-2147483648"), 11));
	if (n < 0)
	{
		result_str[0] = '-';
		n = -n;
	}
	if (n == 0)
		result_str[0] = '0';
	while (n)
	{
		result_str[size_n - 1] = n % 10 + '0';
		size_n--;
		n /= 10;
	}
	return (write(1, result_str, ft_strlen(result_str)));
}
