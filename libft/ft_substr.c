/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:24:56 by hwichoi           #+#    #+#             */
/*   Updated: 2022/04/30 18:29:22 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*buf;

	if (s == 0)
		return (0);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	i = ft_strlen(&s[start]);
	if (i < len)
		len = i;
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (*buf == 0)
		return (0);
	ft_strlcpy(buf, &s[start], len + 1);
	return (buf);
}
