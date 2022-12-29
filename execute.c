/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:19:35 by junykim           #+#    #+#             */
/*   Updated: 2022/12/28 16:23:24 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_cmds(t_tree *tree)
{
	int		status; // signal을 담는 status
	t_cmd	cmd;

	while (1)
	{
		cmd = inorder(tree); // 노드에 저장되어 있는 cmd의 숫자를 반환 후 다음 노드로 
		if (cmd == DOUBLE_PIPE)
			return (do_DP(tree->cmd));
		if (cmd == DOUBLE_AMPER)
			return (do_DA(tree->cmd));
		if (cmd == SINGLE_CMD)
			return (do_SC(tree->cmd));
		if (cmd == SINGLE_PIPE)
			return (do_SP(tree->cmd));
	}
	return (status);
}
