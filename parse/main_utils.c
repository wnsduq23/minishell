/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:26:40 by hwichoi           #+#    #+#             */
/*   Updated: 2022/12/29 16:33:15 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_all(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->env[i])
	{
		free(shell->env[i]);
		shell->env[i] = 0;
		i++;
	}
	free(shell->env);
	shell->env = 0;
}

int	envp_copy(char **envp, t_shell *shell)
{
	int	len;
	int	i;

	len = 0;
	while (envp[len])
		len++;
	shell->env = (char **)malloc(sizeof(char *) * (len + 1));
	if (shell->env == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		shell->env[i] = ft_strdup(envp[i]);
		if (shell->env[i] == 0)
		{
			free_all(shell);
			return (0);
		}
		i++;
	}
	shell->env[i] = 0;
	return (1);
}
