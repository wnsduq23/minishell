/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:12:00 by junykim           #+#    #+#             */
/*   Updated: 2023/01/08 21:46:07 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_every_pid(t_shell *shell)
{
	t_list	*cur;
	int		w_status;

	cur = shell->pid_list;
	while (cur != NULL)
	{
		if (waitpid(-1, &w_status, 0) == shell->last_cmd_pid)
			shell->last_cmd_wstatus = w_status;
		if (WIFSIGNALED(shell->last_cmd_wstatus))
			shell->last_cmd_wstatus += 128;
		cur = cur->next;
	}
	ft_lstclear(&shell->pid_list, free);
}

void	*new_pid(pid_t pid)
{
	pid_t	*tmp;

	tmp = ft_calloc(1, sizeof(*tmp));
	*tmp = pid;
	return (tmp);
}

int	find_in_env(t_shell *shell, char *var_env)
{
	int	j;

	j = 0;
	while (shell->env[j])
	{
		if ((!ft_strncmp(shell->env[j], var_env, ft_strlen(var_env)) \
			&& shell->env[j][ft_strlen(var_env)] == '=') \
		|| (!ft_strncmp(shell->env[j], var_env, ft_strlen(var_env))
			&& shell->env[j][ft_strlen(var_env)] == '\0'))
			break ;
		j++;
	}
	return (j);
}

int	ft_isspace(int n)
{
	if (n == ' ')
		return (1);
	return (0);
}

int	ft_destlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
