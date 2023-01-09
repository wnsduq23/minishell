/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:39:22 by junykim           #+#    #+#             */
/*   Updated: 2023/01/08 22:49:35 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	the_noar_exit(unsigned int nb)
{
	g_rvalue = nb;
	ft_gc_destroy();
	exit(nb % 256);
}

void	the_noar2(unsigned int nb)
{
	ft_putendl_fd("exit", 2);
	g_rvalue = nb;
	ft_gc_destroy();
	exit(nb % 256);
}

void	check_token(t_tok *tok, int i, int j)
{
	if (i > 1)
		return (return_error_exit("exit: ", "", " too many arguments", 1));
	while (tok->args[i][j] == ' ')
		j++;
	if (tok->args[i][j] == '-' || tok->args[i][j] == '+')
		j++;
	while (ft_isdigit(tok->args[i][j]))
		j++;
	if (!tok->args[i][j])
		return ;
	if (!ft_isdigit(tok->args[i][j]) && tok->args[i][j] != ' ')
		return_error_exit("exit: ", tok->args[1],
			": numeric argument required", 255);
	while (tok->args[i][j] == ' ')
		j++;
	if (tok->args[i][j] != ' ' && tok->args[i][j])
		return_error_exit("exit: ", tok->args[1],
			": numeric argument required", 255);
}

void	ft_exit(t_token *tok)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (!tok->prev && !tok->next)
		ft_putendl_fd("exit", 2);
	while (tok->content[++i])
		check_token(tok, i, j);
	if (tok->content[1])
		the_noar_exit(ft_atol(tok->args[1]));
	the_noar_exit(g_rvalue);
}
