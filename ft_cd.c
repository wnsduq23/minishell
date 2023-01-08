/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:37:42 by junykim           #+#    #+#             */
/*   Updated: 2023/01/08 19:38:32 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(t_tree *node, char *str, t_token *tok)
{

}
void	ft_cd2(t_minishell *data, int i, int j, char **cmd_args)
{
	char		**home;
	struct stat	s;

	home = ft_split(data->new_env[j], '=');
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
	data->cd_pwd = getcwd(NULL, 0);
	data->new_env[i] = ft_strjoin("PWD=", data->cd_pwd);
	free(data->cd_pwd);
}

void	ft_cd(t_minishell *data, char **cmd_args, t_lst_cmd *lst_cmd)
{
	int		i;
	int		j;

	i = find_in_env(data, "PWD");
	j = find_in_env(data, "HOME");
	if (j == ft_destlen(data->new_env) && !cmd_args[1])
		return (return_error_builtin("cd: ", "HOME", " not set", 1));
	data->cd_pwd = getcwd(NULL, 0);
	oldpwd(data);
	ft_cd2(data, i, j, cmd_args);
	if (lst_cmd->next || lst_cmd->prev)
		exit(0);
}
