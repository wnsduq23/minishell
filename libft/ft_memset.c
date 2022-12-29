/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:23:35 by hwichoi           #+#    #+#             */
/*   Updated: 2022/04/28 21:23:39 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			cnt;
	unsigned char	*ret;
	unsigned char	input;

	ret = b;
	cnt = 0;
	input = c;
	while (cnt < len)
	{
		*ret = input;
		ret++;
		cnt = cnt + sizeof(char);
	}
	return (b);
}
