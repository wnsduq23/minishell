/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:24:50 by hwichoi           #+#    #+#             */
/*   Updated: 2022/05/17 22:01:11 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ret;

	if (s1 == 0)
		return (0);
	if (set == 0 || *s1 == 0)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != 0 && ft_strchr(set, s1[start]))
		start++;
	while (end - 1 != 0 && ft_strchr(set, s1[end - 1]))
		end--;
	if (start > end)
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * (end - start + 1));
	if (ret == 0)
		return (0);
	ft_strlcpy(ret, &s1[start], end - start + 1);
	return (ret);
}
