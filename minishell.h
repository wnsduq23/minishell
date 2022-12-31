/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:41:12 by junykim           #+#    #+#             */
/*   Updated: 2022/12/31 12:39:52 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// free, malloc
# include <stdlib.h>

// access
# include <unistd.h>

//perror
# include <stdio.h>

# include "libft/libft.h"

typedef enum e_cmd
{
	SINGLE_QUOT,
	DOUBLE_QUOT,
	REDIRECT,
	SIMPLE_CMD
}	t_cmd;

typedef struct s_token
{
	t_cmd			type;
	char			*token;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_tree
{
	t_cmd			type;
	char			**token;
	char			**redir;
	int				is_pipe;
	int				last_pipe_cmd;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

typedef struct s_shell
{
	char	**env;
	int		last_cmd_wstatus;
	char	**paths;
}	t_shell;

/*
 * argv	: "ls" "-al" 
 * cmd	: "ls -al"
 * paths : "/bin/ls"
 */
typedef struct s_cmds
{
	char	**argv;
	char	*cmd;
}			t_cmds;

// ================================
//			execute.c
// ================================
typedef void(*t_callback_func)(t_tree *, int *, t_shell *);
void	delete_node(t_tree *node, int *status, t_shell *shell);
void	execute_node(t_tree *node, int *status, t_shell *shell);
void	inorder_recur(t_tree *node, int *status, t_callback_func callback, \
			t_shell *shell);
int		execute(t_tree *tree, t_shell *shell);

// ================================
//			cmd1.c
// ================================
char	*get_cmd(char **paths, char *cmd);
void	exec_cmd(t_tree *node, char *cmd, t_shell *shell);
void	exec_operator(t_tree *node, t_token *tok, int *status, t_shell *shell);
#endif
