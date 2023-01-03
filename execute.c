/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:19:35 by junykim           #+#    #+#             */
/*   Updated: 2022/12/31 14:55:47 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_node(t_tree *node, int *status, t_shell *shell)
{
	(void)status;
	(void)shell;
	if (node != NULL)
	{
		if ((node)->redir != NULL)
			ft_lstclear(&node->redir, delete_token);
		if (node->token != NULL)
			ft_lstclear(&node->token, delete_token);
		free(node);
		node = NULL;
	}
}

/* 
 * if token = "ls" "-al"
 * tok -> "ls"
 * cmd -> "/bin/ls/ls"
 */
void	execute_node(t_tree *node, int *status, t_shell *shell)
{
	t_token	*tok;
	t_cmd	tok_type; 
	char	*cmd;

	tok = NULL;
	if (node->token != NULL)
		tok->token = node->token[0];
	if (tok->token != NULL && tok_type != SIMPLE_CMD)
		exec_operator(node, tok, status, shell);
	cmd = get_cmd(shell->paths, tok->token);
	if (cmd == NULL)
	{
		ft_perror(cmd, ": command not found");
		give_signal();
		status = 127;
		return ;
	}
	exec_cmd(node, cmd ,shell);
}


void	inorder_recur(t_tree *node, int *status, t_callback_func callback, \
			t_shell *shell)
{
	if (node == NULL) // 리스트 포인터를 NULL로 초기화 해놔야함 
		return ;
	if (callback != delete_node)
	{
		inorder_recur(node->left, status, callback, shell);
		callback(node, status, shell);
		inorder_recur(node->right, status, callback, shell);
	}
	else if (callback == delete_node)
	{
		inorder_recur(node->left, status, callback, shell);
		inorder_recur(node->right, status, callback, shell);
		callback(node, status, shell);
	}
}

int	execute(t_tree *tree, t_shell *shell)
{
	int	status;

	inorder_recur(tree, &status, execute_node, shell);
	wait_every_pid(shell);
	inorder_recur(tree, &status, delete_node, shell);
	//g_is_sig_interrupt = false;
	return (WEXITSTATUS(shell->last_cmd_wstatus));
}
