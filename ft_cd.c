/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:37:42 by junykim           #+#    #+#             */
/*   Updated: 2023/01/08 22:27:13 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd2(t_shell *shell, int i, int j, char **cmd_args)
{
	char		**home;
	struct stat	s;

	home = ft_split(shell->env[j], '=');
	stat(cmd_args[1], &s);
	if (S_ISREG(s.st_mode))
		return (return_error_builtin("cd: ", cmd_args[1],
				": Not a directory", 1));
	if (access(cmd_args[1], X_OK) == -1 && access(cmd_args[1], F_OK) == 0)
		return (return_error_builtin("cd: ", cmd_args[1],
				": Permision denied", 1));
	else if (cmd_args[1])
	{
		if (chdir(cmd_args[1]) == -1)
			return (return_error_builtin("cd: ", cmd_args[1],
					": No such file or directory", 1));
	}
	else if (!cmd_args[1])
		chdir(home[1]);
	shell->cd_pwd = getcwd(NULL, 0);
	shell->env[i] = ft_strjoin("PWD=", shell->cd_pwd);
	free(shell->cd_pwd);
}

void	ft_cd(char **cmd_args, t_token *tok, t_shell *shell)
{
	int		pwd_idx;
	int		home_idx;

	pwd_idx = find_in_env(shell, "PWD");
	home_idx = find_in_env(shell, "HOME");
	if (home_idx == ft_destlen(shell->env) && !cmd_args[1])
		return (return_error_builtin("cd: ", "HOME", " not set", 1));
	shell->cd_pwd = getcwd(NULL, 0);
	ft_oldpwd(data);
	ft_cd2(shell, pwd_idx, home_idx, cmd_args);
	if (tok->next || tok->prev)
		exit(0);
}
