/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:24:44 by hwichoi           #+#    #+#             */
/*   Updated: 2022/04/30 15:00:30 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	*buf;
	unsigned char	to_find;

	buf = (unsigned char *)s;
	len = ft_strlen((char *)buf);
	to_find = (unsigned char)c;
	while (len > 0)
	{
		if (buf[len] == to_find)
			return ((char *)&buf[len]);
		len--;
	}
	if (buf[0] == to_find)
		return ((char *)&buf[len]);
	return (0);
}
