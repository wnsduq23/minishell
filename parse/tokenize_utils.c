/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:16:54 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/03 22:15:56 by hwichoi          ###   ########.fr       */
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
		free(buf->content);
		free(buf);
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

t_token	*first_token(t_token *token)
{
	while(token->prev)
		token = token->prev;
	return (token);
}

t_token	*token_div(t_token *token, int size)
{
	t_token	*new;
	char	*prev_char;
	char	*buf;

	if (size == 0 || size == ft_strlen(token->content))
		return (token);
	prev_char = ft_substr(token->content, 0, size);
	new = new_token(prev_char);
	new->prev = token->prev;
	new->next = token;
	buf = token->content;
	token->content = ft_substr(token->content, size, \
			ft_strlen(token->content) - size);
	token->prev = new;
	free(buf);
	return (token);
}

void	div_error(char c, t_token *token)
{
	clear_token(token);
	print_error(c);
}
