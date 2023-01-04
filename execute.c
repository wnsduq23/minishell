/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:19:35 by junykim           #+#    #+#             */
/*   Updated: 2023/01/04 19:10:51 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
# define true (1)
# define false (0)

void	delete_node(t_tree *node, t_shell *shell)
{
	(void)shell;
	if (node != NULL)
	{
		if ((node)->redir != NULL)
			/** ft_lstclear(&node->redir, delete_token); */
		if (node->token != NULL)
			/** ft_lstclear(&node->token, delete_token); */
		free(node);
		node = NULL;
	}
}

int	is_builtin(t_token *tok)
{
	if (tok->token == NULL)
		return (0);
	if ((ft_strncmp(tok->token, "env",
				ft_strlen(tok->token) + 1) == 0)
		|| (ft_strncmp(tok->token, "pwd",
				ft_strlen(tok->token) + 1) == 0)
		|| (ft_strncmp(tok->token, "echo",
				ft_strlen(tok->token) + 1) == 0))
	{
		return (1);
	}
	else if (ft_strncmp(tok->token, "cd",
			ft_strlen(tok->token) + 1) == 0
		|| (ft_strncmp(tok->token, "exit",
				ft_strlen(tok->token) + 1) == 0)
		|| (ft_strncmp(tok->token, "export",
				ft_strlen(tok->token) + 1) == 0)
		|| (ft_strncmp(tok->token, "unset",
				ft_strlen(tok->token) + 1) == 0))
		return (2);
	else
		return (0);
}

/* 
 * if token = "ls" "-al"
 * tok -> "ls"
 * cmd -> "/bin/ls/ls"
 */
void	execute_node(t_tree *node, t_shell *shell)
{
	t_token	*tok;

	/** if (check_redir(node) == -1) */
	/**     return ; */
	tok = NULL;
	if (node->token != NULL)
		tok->token = node->token[0];
	/** if (is_builtin(tok) == 2) */
	/**     exec_builtin(node, tok); */
	exec_external(node, tok, shell);
}

void	inorder_recur(t_tree *node, t_callback_func callback, \
			t_shell *shell)
{
	if (node == NULL) // 리스트 포인터를 NULL로 초기화 해놔야함 
		return ;
	if (callback != delete_node)
	{
		inorder_recur(node->left, callback, shell);
		callback(node, shell);
		inorder_recur(node->right, callback, shell);
	}
	else if (callback == delete_node)
	{
		inorder_recur(node->left, callback, shell);
		inorder_recur(node->right, callback, shell);
		callback(node, shell);
	}
}

int	execute(t_tree *tree, t_shell *shell)
{
	inorder_recur(tree, execute_node, shell);
	/** wait_every_pid(shell); */
	inorder_recur(tree, delete_node, shell);
	//g_is_sig_interrupt = false;
	return (WEXITSTATUS(shell->last_cmd_wstatus));
}
