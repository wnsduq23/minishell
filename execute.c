/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:19:35 by junykim           #+#    #+#             */
/*   Updated: 2023/01/08 18:47:45 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (tok->content == NULL)
		return (0);
	if ((ft_strncmp(tok->content, "env",
				ft_strlen(tok->content) + 1) == 0)
		|| (ft_strncmp(tok->content, "pwd",
				ft_strlen(tok->content) + 1) == 0)
		|| (ft_strncmp(tok->content, "echo",
				ft_strlen(tok->content) + 1) == 0))
	{
		return (1);
	}
	else if (ft_strncmp(tok->content, "cd",
			ft_strlen(tok->content) + 1) == 0
		|| (ft_strncmp(tok->content, "exit",
				ft_strlen(tok->content) + 1) == 0)
		|| (ft_strncmp(tok->content, "export",
				ft_strlen(tok->content) + 1) == 0)
		|| (ft_strncmp(tok->content, "unset",
				ft_strlen(tok->content) + 1) == 0))
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
	tok = malloc(sizeof(t_token));
	tok->stdout = 4;
	tok->stdin = 3;
	tok->content = malloc(sizeof(char) * ft_strlen(node->token[0]) + 1);
	if (node->token != NULL)
		tok->content = node->token[0];
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
	wait_every_pid(shell);
	inorder_recur(tree, delete_node, shell);
	return (WEXITSTATUS(shell->last_cmd_wstatus));
}
