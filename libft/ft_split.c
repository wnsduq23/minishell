/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:23:42 by hwichoi           #+#    #+#             */
/*   Updated: 2022/05/17 21:45:55 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**alloc_split(char const *s, char c, int *size)
{
	int		i;
	char	**buf;

	i = -1;
	*size = 0;
	while (s[++i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == 0))
			(*size)++;
	}
	buf = (char **)malloc(sizeof(char *) * (*size + 1));
	if (buf == 0)
		return (0);
	buf[*size] = 0;
	return (buf);
}

static char	*alc_cpy(char const *s, int size)
{
	char	*buf;
	int		i;

	buf = (char *)malloc(sizeof(char) * (size + 1));
	if (buf == 0)
		return (0);
	i = -1;
	while (++i < size && s[i])
		buf[i] = s[i];
	buf[i] = 0;
	return (buf);
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**buf;
	int		i;
	int		cnt;
	int		cpy;

	if (s == 0)
		return (0);
	i = -1;
	cnt = 0;
	size = 0;
	buf = alloc_split(s, c, &size);
	if (buf == 0)
		return (0);
	while (s[cnt] && ++i < size)
	{
		while (s[cnt] == c && s[cnt])
			cnt++;
		cpy = cnt;
		while (s[cnt] != c && s[cnt])
			cnt++;
		buf[i] = alc_cpy(&s[cpy], cnt - cpy);
		if (buf == 0)
			return (0);
	}
	return (buf);
}
