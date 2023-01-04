/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:41:12 by junykim           #+#    #+#             */
/*   Updated: 2023/01/04 19:01:22 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

int	g_rvalue;
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

//stat
#include <sys/stat.h>

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
	char			*path;
	int				stdin;
	int				stdout;
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
}	t_shell;

/*
 * argv	: "ls" "-al" 
 * cmd	: "ls -al"
 * paths : "/bin/ls"
 */

// ================================
//			execute.c
// ================================
typedef void(*t_callback_func)(t_tree *, t_shell *);
void	delete_node(t_tree *node, t_shell *shell);
void	execute_node(t_tree *node, t_shell *shell);
int		is_builtin(t_token *tok);
void	inorder_recur(t_tree *node, t_callback_func callback, \
			t_shell *shell);
int		execute(t_tree *tree, t_shell *shell);

// ================================
//			exec_cmd.c
// ================================
void	exec_builtin(t_tree *node, t_token *tok);
void	exec_external(t_tree *node, t_token *tok, t_shell *shell);
int		child_process(int *pipe_fd, t_tree *node, t_token *tok, t_shell *shell);
void	do_execve(t_token *tok, t_tree *node, t_shell *shell);
void	check_path_permission(t_token *tok, t_tree *node, t_shell *shell);

// ================================
//			exec_cmd_util.c
// ================================
char	*get_cmd(char **envp, char *cmd);
void	init_dup(t_tree *node, t_token *tok, int *pipe_fd);

// ================================
//			redirection.c
// ================================
int		open_file_input(t_list *cur, int *pipe_fd, int *status);
int		open_file_heredoc(t_list *cur, int *pipe_fd, int *status, \
			t_shell *shell);
int		open_file_output(t_list *cur, int *pipe_fd, int *status);
int		open_file_append(t_list *cur, int *pipe_fd, int *status);
int		open_redirection(int *pipe_fd, t_list *redir_list, \
			t_shell *shell);

// ================================
//			cmd_builtin1.c
// ================================

// ================================
//			cmd_builtin2.c
// ================================

// ================================
//			cmd_builtin2.c
// ================================
void	delete_token();

// ================================
//			error.c
// ================================
void	return_error_2(char *arg, char *msg, int nb);
void	ft_perror(char  *string);

// ================================
//				util.c
// ================================
void	wait_every_pid(t_shell *shell);
#endif
