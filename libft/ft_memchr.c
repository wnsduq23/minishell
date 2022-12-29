/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:23:00 by hwichoi           #+#    #+#             */
/*   Updated: 2022/04/28 21:23:07 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned char	*cb;
	unsigned char	to_find;
	size_t			cnt;

	cb = (unsigned char *)b;
	to_find = (unsigned char)c;
	cnt = 0;
	while (cnt < len)
	{
		if (cb[cnt] == to_find)
			return ((void *)&cb[cnt]);
		cnt++;
	}
	return (0);
}
