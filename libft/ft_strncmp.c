/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:24:33 by hwichoi           #+#    #+#             */
/*   Updated: 2022/04/30 15:14:04 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			cnt;
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	cnt = 0;
	while (cnt < n)
	{
		if (cs1[cnt] == 0 || cs2[cnt] == 0 || cs1[cnt] != cs2[cnt])
			return (cs1[cnt] - cs2[cnt]);
		cnt++;
	}
	return (0);
}
