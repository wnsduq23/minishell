/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:19:52 by hwichoi           #+#    #+#             */
/*   Updated: 2022/12/31 21:00:02 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_token *quotes_div(t_token *token)
{
	

t_token	*tokenize(char *line)
{
	t_token	*tokens;
	int		len;

	len = 0;
	tokens = new_token(line);
	tokens = quotes_div(token);