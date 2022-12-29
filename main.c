/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:17:16 by hwichoi           #+#    #+#             */
/*   Updated: 2022/12/28 17:40:32 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"
#include "./libft/libft.h"

void	start_loop(char **envp)
{
	char	*line;
	
	while (1)
	{}
}

void	envp_copy(char **envp, t_shell *shell)
{
	int	len;
	int i;

	len = 0;
	while (envp[len] == 0)
		len++;
	shell->env = (char **)malloc(sizeof(char *) * (len + 1));
	if (shell->env == 0)
		return ;
	i = 0;
	while (i < len)
	{
		ft_memcpy(shell->env[i], envp[i], ft_strlen(envp[i]));
		i++;
	}
	shell->env[i] = 0;
}

int	main(int ac, char **av, char **envp)
{
	t_shell	shell;	

	(void)ac;
	(void)av;
	envp_copy(envp, &shell);
	for (int i=0; shell.env[i]; i++)
		printf("%s\n", shell.env[i]);
/*	start_loop(env);*/
	return (0);
}
