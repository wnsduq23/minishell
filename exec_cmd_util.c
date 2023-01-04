/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:44:14 by junykim           #+#    #+#             */
/*   Updated: 2023/01/04 19:00:56 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

void init_dup(t_tree *node, t_token *tok, int *pipe_fd)
{
	int	tmp_fd;

	if (node->last_pipe_cmd)
		dup2(tok->stdout, pipe_fd[WRITE]);
	tmp_fd = pipe_fd[READ];
	/** status = open_redirection(pipe_fd, node->redirection, shell); */
	/** if (status != SUCCESS) */
	/**     exit(status); */
	if (tmp_fd != pipe_fd[READ])
		dup2(pipe_fd[READ], STDIN_FILENO);
	dup2(pipe_fd[WRITE], STDOUT_FILENO);
	close(pipe_fd[WRITE]);
	close(pipe_fd[READ]);
}

char	*get_cmd(char **envp, char *cmd)
{
	char	*tmp;
	char	*command;
	char	**paths;

	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	paths = ft_split((*envp + 5), ':');
	if (!paths)
		return ("nopath");
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}
