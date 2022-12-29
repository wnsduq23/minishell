/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:19:52 by hwichoi           #+#    #+#             */
/*   Updated: 2022/12/29 21:22:11 by hwichoi          ###   ########.fr       */
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
	ret->token = content;
	ret->prev = 0;
	ret->next = 0;
	return (ret);
}

t_token	*tokenize(char *line)
{
	t_token	*tokens;
	t_token	*current;
	int		len;

	current = tokens;
	len = 0;
	while (*line)
	{
		while (
