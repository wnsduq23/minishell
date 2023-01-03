/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:15:48 by junykim           #+#    #+#             */
/*   Updated: 2023/01/03 18:42:24 by junykim          ###   ########.fr       */
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

int	exec_builtin(char **cmd_argv, char ***envp, t_shell *shell)
{
	size_t	len;
	int		status;

	len = ft_strlen(cmd_argv[0]);
	if (ft_strncmp("cd", cmd_argv[0], len + 1) == 0)
		status = exec_cd(cmd_argv, envp);
	else if (ft_strncmp("exit", cmd_argv[0], len + 1) == 0)
		status = exec_exit(cmd_argv, *envp, shell);
	else if (ft_strncmp("export", cmd_argv[0], len + 1) == 0)
		status = exec_export(cmd_argv, envp);
	else if (ft_strncmp("env", cmd_argv[0], len + 1) == 0)
		status = exec_env(cmd_argv, *envp);
	else if (ft_strncmp("echo", cmd_argv[0], len + 1) == 0)
		status = exec_echo(cmd_argv, *envp);
	else if (ft_strncmp("pwd", cmd_argv[0], len + 1) == 0)
		status = exec_pwd(cmd_argv, *envp);
	else if (ft_strncmp("unset", cmd_argv[0], len + 1) == 0)
		status = exec_unset(cmd_argv, envp);
	else
		status = ERROR;
	return (status);
}

//NOTE: : it isn't be forked ? 
//NOTE: : for builtin command
void	exec_exceptions(t_tree *node, t_token *tok, int *status, t_shell *shell)
{
	int	pipe_fd[2];
	int	status;

	pipe_fd[READ] = shell->stdin;
	pipe_fd[WRITE] = shell->stdout;
}

//NOTE: : for PATH command
//TODO: : 잘못된 cmd인 경우 오류 출력만 하고 계속 수행한다.  
//WARN: : 병렬적으로 수행되는지 확인 
void	exec_general(t_tree *node, char *cmd, t_shell *shell)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
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
		child_process(pipe_fd, node, cmd, shell);
	wait_every_pid();
}
