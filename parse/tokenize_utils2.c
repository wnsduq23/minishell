/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:01:36 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/03 22:20:00 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	show_tokens(t_token *token)
{
	while (token)
	{
		printf("content: %s\n", token->content);
		token = token->next;
	}
}

t_token	*del_prev(t_token *token)
{
	t_token	*buf;

	buf = token->prev;
	token->prev = token->prev->prev;
	token->prev->next = token;
	free(buf->content);
	free(buf);
	return (token);
}
