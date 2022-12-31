/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:16:54 by hwichoi           #+#    #+#             */
/*   Updated: 2022/12/31 18:18:52 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	clear_token(t_token **token)
{
	t_token	*buf;

	while (*token != 0)
	{
		buf = *token;
		*token = (*token)->next;
		free((*token)->content);
		free(*token);
	}
}

t_token	*new_token(char *content)
{
	t_token	*ret;

	ret = (t_token *)malloc(sizeof(t_token));
	if (ret == 0)
		return (0);
	ret->content = content;
	ret->prev = 0;
	ret->next = 0;
	return (ret);
}
