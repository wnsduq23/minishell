/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:24:17 by hwichoi           #+#    #+#             */
/*   Updated: 2022/04/30 14:41:24 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = 0;
	while (src[srcsize] != '\0')
		srcsize++;
	if (dstsize == 0)
		return (srcsize);
	i = 0;
	while (i < (dstsize - 1) && src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (srcsize);
}
