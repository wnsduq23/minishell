/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:17:16 by hwichoi           #+#    #+#             */
/*   Updated: 2022/12/29 19:25:46 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>

int	start_line(char *line, t_shell *shell)
{
	t_token	*tokens;
	t_tree	*tree;

	tokens = tokenize(line);
}

void	start_loop(t_shell *shell)
{
	char	*line;

	while (1)
	{
		line = readline("input> ");
		if (line == 0)
		{
			printf("exit\n");
			exit(-1);
		}
		else if (*line != '\0')
			add_hitory(line);
		else
		{
			free(line);
			line = 0;
			continue ;
		}
		start_line(line, shell);
		free(line);
		line = 0;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_shell	shell;	

	(void)ac;
	(void)av;
	envp_copy(envp, &shell);
	for (int i=0; shell.env[i]; i++)
		printf("%s\n", shell.env[i]);
	printf("%s\n", getenv("USER"));
	start_loop(&shell);
	return (0);
}
