/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:12:00 by junykim           #+#    #+#             */
/*   Updated: 2023/01/03 22:15:27 by junykim          ###   ########.fr       */
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
