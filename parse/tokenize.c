/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:19:52 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/03 22:11:20 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_token *quotes_div(t_token *token)
{
	int		size;
	char	quotes;
	char	*line;
	t_token	*ret;

	size = 0;
	line = token->content;
	while (line[size] != ''' && line[size] != '"' && line[size] != '\0')
		size++;
	if (line[size] == '\0')
		return (token);
	quotes = line[size];
	ret = token_div(token, size);
	line = ret->content;
	size = 1;
	while (line[size] != quotes && line[size] != '\0')
		size++;
	if (quotes && line[size] == '\0')
		div_error(quotes);
	ret = token_div(ret, size + 1);
	return (quotes_div(ret));
}

t_token	*pipe_div(t_token *token)
{
	int		size;
	char	*line;
	t_token	*ret;

	size = 0;
	line = token->content;
	while (line[size] != '|' && line[size] != '\0')
		size++;
	if (line[size] == '\0')
		return (token);
	ret = token_div(token, size);
	line = ret->content;
	ret = token_div(ret, 1);
	return (pipe_div(ret));
}

t_token	*redir_div(t_token *token)
{
	int		size;
	char	*line;
	char	redir;
	t_token	*ret;

	size = 0;
	line = token->content;
	while (line[size] != '<' && line[size] != '>' && line[size] != '\0')
		size++;
	if (line[size] == '\0')
		return (token);
	ret = token_div(token, size);
	redir = line[size];
	line = ret->content;
	while (line[size] == redir)
		size++;
	ret = token_div(ret, size);
	return (redir_div(ret));
}

t_token	*space_div(t_token *token)
{
	int		size;
	char	*line;
	t_token	*ret;
	
	size = 0;
	line = token->content;
	while (!ft_isspace(line[size]) && line[size] != '\0')
		size++;
	if (line[size] == '\0')
		return (token);
	ret = token_div(token, size);
	line = ret->content;
	while (ft_isspace(line[size]))
		size++;
	ret = token_div(ret, size);
	ret = del_prev(ret);
	return (space_div(ret));
}

t_token	*tokenize(char *line)
{
	t_token	*tokens;
	int		len;

	len = 0;
	tokens = new_token(ft_strdup(line));
	tokens = quotes_div(token);
	tokens = first_token(token);
	while (tokens)
	{
		tokens = pipe_div(token);
		tokens = tokens->next;
	}
	return (tokens);
}
