/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:41:12 by junykim           #+#    #+#             */
/*   Updated: 2023/01/03 18:43:45 by junykim          ###   ########.fr       */
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

// open, close .. 
#include <fcntl.h>

//wait
#include <sys/wait.h>

# include "libft/libft.h"

typedef enum e_cmd
{
	SINGLE_QUOT,
	DOUBLE_QUOT,
	REDIRECT,
	SIMPLE_CMD
}	t_cmd;

# define READ	(0)
# define WRITE	(1)

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
	int		stdout;
	int		stdin;
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

// ================================
//			redirection.c
// ================================
int	open_file_input(t_list *cur, int *pipe_fd, int *status);
int	open_file_heredoc(t_list *cur, int *pipe_fd, int *status, \
		t_shell *shell);
int	open_file_output(t_list *cur, int *pipe_fd, int *status);
int	open_file_append(t_list *cur, int *pipe_fd, int *status);
int	open_redirection(int *pipe_fd, t_list *redir_list, \
			t_shell *shell);

#endif
