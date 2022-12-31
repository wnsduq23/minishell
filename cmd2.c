/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:44:14 by junykim           #+#    #+#             */
/*   Updated: 2022/12/31 12:36:51 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * cmd를 수행할 자식 process를 만든다.
 */
void	child_process(t_tree *node, char *cmd, t_shell *shell)
{
	execve(cmd, node->token, shell->env);
	exit(0);
}
