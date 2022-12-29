/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:20:53 by hwichoi           #+#    #+#             */
/*   Updated: 2022/04/28 21:21:00 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *b, size_t len)
{
	size_t			cnt;
	unsigned char	*ret;

	ret = b;
	cnt = 0;
	while (cnt < len)
	{
		*ret = 0;
		ret++;
		cnt = cnt + sizeof(char);
	}
	return (b);
}
