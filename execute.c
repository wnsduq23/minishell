/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:19:35 by junykim           #+#    #+#             */
/*   Updated: 2022/12/28 13:46:54 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	execute_cmds(t_tree *tree)
{
	int	status; // signal을 담는 status
	int	cmd;

	while (1)
	{
		cmd = inorder(); // 트리를 순회, 노드에 저장되어 있는 cmd의 숫자를 반환
		if (cmd == DOUBLE_PIPE)
			return (do_DP());
		if (cmd == DOUBLE_AMPER)
			return (do_DA());
		if (cmd == SINGLE_CMD)
			return (do_SC());
		if (cmd == SINGLE_PIPE)
			return (do_SP());
	}
	return (status);
}
