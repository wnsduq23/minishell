/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:23:19 by hwichoi           #+#    #+#             */
/*   Updated: 2022/04/30 14:36:50 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*c_dest;
	unsigned char	*c_src;
	size_t			cnt;

	cnt = 0;
	if (len == 0)
		return (dest);
	c_dest = (unsigned char *)dest;
	c_src = (unsigned char *)src;
	if (dest < src)
	{
		while (++cnt <= len)
			*c_dest++ = *c_src++;
	}
	else
	{
		c_dest += len - 1;
		c_src += len - 1;
		while (++cnt <= len)
			*c_dest-- = *c_src--;
	}
	return (dest);
}
