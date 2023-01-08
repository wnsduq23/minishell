/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:34:03 by junykim           #+#    #+#             */
/*   Updated: 2023/01/08 17:26:40 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(t_shell *shell)
{
	int		i;
	char	**dest;

	dest = shell->env;
	i = 0;
	while (dest[i])
	{
		if (ft_strchr(dest[i], '='))
			ft_putendl_fd(dest[i], 1);
		i++;
	}
	exit(0);
}
