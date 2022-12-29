/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:15:48 by junykim           #+#    #+#             */
/*   Updated: 2022/12/29 20:51:38 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/wait.h>
# define SUCCESS 0

 char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

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

//XXX: : A || B if A fail, execute B
//XXX: : A && B , if A is success, execute B
//NOTE: : it isn't be forked ? 
//
void	exec_operator(t_tree *node, t_token *tok, int *status, t_shell *shell)
{
	if (tok->type == BRACKET)
		*status = exec_subshell(node, tok->str, shell);
	else if (tok->type == DOUBLE_AMPERSAND)
	{
		wait_every_pid(shell);
		if (WEXITSTATUS(shell->last_cmd_wstatus) != SUCCESS)
			*status = 1;
	}
	else if (tok->type == DOUBLE_PIPE)
	{
		wait_every_pid(shell);
		if (WEXITSTATUS(shell->last_cmd_wstatus) == SUCCESS)
			*status = 1;
	}
	return ;
}

//TODO: : 잘못된 cmd인 경우 오류 출력만 하고 계속 수행한다.  
//WARN: : fork -> child process does
void	exec_cmd(t_tree *node, char *cmd, t_shell *shell)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		ft_perror("pipe error");
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		ft_perror("fork error");
		return ;
	}
	if (pid == 0) 
		child_process();
	execve(cmd, node->token, shell->env);
}
