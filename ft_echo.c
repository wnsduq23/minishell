/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:32:43 by junykim           #+#    #+#             */
/*   Updated: 2023/01/06 16:32:59 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_flag(char *arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (0);
	if (arg[i] == '-' && arg[i + 1] != '\0')
	{
		i++;
		while (arg[i])
		{
			if (arg[i] == 'n')
				i++;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}

void	ft_echo(char **args)
{
	int	i;
	int	flag;

	i = 1;
	flag = ft_flag(args[i]);
	if (flag)
		while (ft_flag(args[i]))
			i++;
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (!flag)
		ft_putchar_fd('\n', 1);
}
