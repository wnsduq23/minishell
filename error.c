/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:14:36 by junykim           #+#    #+#             */
/*   Updated: 2023/01/04 18:19:20 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_perror(char  *string)
{
	write(1, string, ft_strlen(string));
	exit(1);
}

void	return_error_2(char *arg, char *msg, int nb)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd(msg, 2);
	g_rvalue = nb % 256;
	exit(nb % 256);
}

