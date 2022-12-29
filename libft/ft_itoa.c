/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:22:22 by hwichoi           #+#    #+#             */
/*   Updated: 2022/05/17 21:31:09 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	dig_size(long n)
{
	int	dig;

	dig = 0;
	if (n <= 0)
	{
		n *= -1;
		dig++;
	}
	while (n > 0)
	{
		n = n / 10;
		dig++;
	}
	return (dig);
}

char	*ft_itoa(int n)
{
	char	*buf;
	int		size;
	long	nbr;

	nbr = (long)n;
	size = dig_size(nbr);
	buf = (char *)malloc(sizeof(char) * (size + 1));
	if (buf == 0)
		return (0);
	if (nbr < 0)
	{
		nbr *= -1;
		buf[0] = '-';
	}
	buf[size] = 0;
	if (nbr == 0)
		buf[0] = '0';
	while (nbr > 0)
	{
		buf[--size] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (buf);
}
