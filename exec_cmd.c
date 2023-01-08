/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:15:48 by junykim           #+#    #+#             */
/*   Updated: 2023/01/08 20:17:11 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define SUCCESS 0
//NOTE: : it isn't be forked ? 
//NOTE: : for builtin command
/*void	exec_builtin(t_tree *node, t_token *tok, t_shell *shell)
{
	if (ft_strncmp(tok->content, "cd", ft_strlen("cd")) == 0)
		ft_cd(node, tok->content, tok);
	if (ft_strncmp(tok->content, "env", ft_strlen("env")) == 0)
		env(node);
	if (ft_strncmp(tok->content, "unset", ft_strlen("unset")) == 0)
		ft_unset(node, tok->content);
	if (ft_strncmp(tok->content, "pwd", ft_strlen("pwd")) == 0)
		ft_pwd();
	if (ft_strncmp(tok->content, "export", ft_strlen("export")) == 0)
		ft_export(node, tok, shell);
	if (ft_strncmp(tok->content, "exit", ft_strlen("exit")) == 0)
		ft_exit(tok);
	if (ft_strncmp(tok->content, "echo", ft_strlen("echo")) == 0)
		ft_echo(tok->content); // args가 char **인데 ? 
} */

void	do_execve(t_token *tok, t_tree *node, t_shell *shell)
{
	struct stat	s;

	stat(tok->path, &s);
	if (tok->path[0] == '/')
	{
		if (!S_ISDIR(s.st_mode) && !S_ISREG(s.st_mode))
			return_error_2(tok->content,
				": No such file or directory", 127);
		if (access(tok->path, X_OK) == -1
			&& access(tok->path, F_OK) == 0)
			return_error_2(tok->content, ": Permission denied", 126);
		if (execve(tok->path, node->token, shell->env) < 0)
			return_error_2(tok->content,
				": command not found", 127);
	}
	if (execve(tok->path, node->token, shell->env) == -1
		&& ft_strlen(tok->content))
		return_error_2(tok->content,
			": command not found", 127);
	else
		exit (0);
}

void	check_path_permission(t_token *tok, t_tree *node, t_shell *shell)
{
	struct stat	s;

	stat(tok->path, &s);
	if (S_ISDIR(s.st_mode))
		return_error_2(tok->content, ": is a directory", 126);
	if (access(tok->path, X_OK) == -1
		&& access(tok->path, F_OK) == 0)
		return_error_2(tok->content, ": Permission denied", 126);
	if (execve(tok->path, node->token, shell->env) == -1)
		return_error_2(tok->content,
			": No such file or directory", 127);
}

int	child_process(int *pipe_fd, t_tree *node, t_token *tok, t_shell *shell)
{
	/** signal(SIGINT, ft_ctrl_c_fork); */
	/** signal(SIGQUIT, ft_ctrl_f_bslash); */
	/** signal(SIGINT, sig_exit); */
	init_dup(node, tok, pipe_fd);
	tok->path = get_cmd(shell->env, tok->content);
	/** if (is_builtin(tok) != 0) */
	/** { */
	/**     exec_builtin(node, tok); */
	/**     exit(0); */
	/** } */
	if (ft_strncmp(tok->path, "nopath", 6) == 0)
		return_error_2(tok->content,
				": No such file or directory", 127);
	else if (tok->path[0] == '.' && tok->path[1] == '/')
		check_path_permission(tok, node, shell);
	else
		do_execve(tok, node, shell);
	return (0);
}

//NOTE: : for PATH command
//TODO: : 잘못된 cmd인 경우 오류 출력만 하고 계속 수행한다. 
//WARN: : 병렬적으로 수행되는지 확인 
void	exec_external(t_tree *node, t_token *tok, t_shell *shell)
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
		child_process(pipe_fd, node, tok, shell);
	else
	{
		ft_lstadd_back(&shell->pid_list, ft_lstnew(new_pid(pid)));
		shell->last_cmd_pid = pid;
	}
	wait_every_pid(shell);
}
