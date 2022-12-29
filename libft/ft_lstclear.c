/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:02:42 by hwichoi           #+#    #+#             */
/*   Updated: 2022/05/17 21:39:54 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buf;

	if (lst == 0 || del == 0 || *lst == 0)
		return ;
	while (*lst != NULL)
	{
		buf = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(buf, del);
	}
}
