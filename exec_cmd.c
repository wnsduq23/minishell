/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:15:48 by junykim           #+#    #+#             */
/*   Updated: 2023/01/03 22:21:30 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	exec_builtin(char **cmd_argv, char **envp, t_shell *shell)
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
int	exec_builtin_cmd(t_tree *node, char **cmd_argv, t_shell *shell)
{
	int	fd[2];
	int	status;

	fd[READ] = shell->stdin;
	fd[WRITE] = shell->stdout;
	status = open_redirection(fd, node->redirection, shell);
	if (status != SUCCESS)
		return (status);
	if (fd[READ] != shell->stdin)
	{
		dup2(fd[READ], STDIN_FILENO);
		close(fd[READ]);
	}
	if (fd[WRITE] != shell->stdout)
	{
		dup2(fd[WRITE], STDOUT_FILENO);
		close(fd[WRITE]);
	}
	status = exec_builtin(cmd_argv, shell->env, shell);
	if (fd[READ] != shell->stdin)
		dup2(shell->stdin, STDIN_FILENO);
	if (fd[WRITE] != shell->stdout)
		dup2(shell->stdout, STDOUT_FILENO);
	return (status);
}
//NOTE: : for PATH command
//TODO: : 잘못된 cmd인 경우 오류 출력만 하고 계속 수행한다. 
//WARN: : 병렬적으로 수행되는지 확인 
void	exec_path_cmd(t_tree *node, char *cmd, t_shell *shell)
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
	wait_every_pid(shell);
}
