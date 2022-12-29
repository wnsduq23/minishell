/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:23:49 by hwichoi           #+#    #+#             */
/*   Updated: 2022/04/30 14:57:57 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	to_find;
	int				i;
	unsigned char	*buf;

	to_find = (unsigned char)c;
	i = 0;
	buf = (unsigned char *)s;
	while (buf[i] != 0)
	{
		if (buf[i] == to_find)
			return ((char *)&buf[i]);
		i++;
	}
	if (buf[i] == to_find)
		return ((char *)&buf[i]);
	return (0);
}
