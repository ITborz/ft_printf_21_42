/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:28:08 by bkristen          #+#    #+#             */
/*   Updated: 2022/01/04 18:04:11 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_len_u(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int	ft_itoa_u(unsigned int n)
{
	int		i;
	char	result_str[12];

	i = ft_get_len_u(n);
	result_str[i] = '\0';
	while (n)
	{
		result_str[i - 1] = n % 10 + '0';
		i--;
		n /= 10;
	}
	return (write(1, result_str, ft_strlen(result_str)));
}
