/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:24:38 by hwichoi           #+#    #+#             */
/*   Updated: 2022/05/17 21:57:21 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b_len;
	size_t	l_len;
	size_t	cnt;

	if (*little == '\0')
		return ((char *)big);
	l_len = ft_strlen(little);
	b_len = ft_strlen(big);
	if (b_len < l_len || len < l_len)
		return (0);
	cnt = 0;
	while (cnt < (len - l_len + 1) && cnt < b_len)
	{
		if (ft_strncmp(&big[cnt], little, l_len) == 0)
			return ((char *)&big[cnt]);
		cnt++;
	}
	return (0);
}
