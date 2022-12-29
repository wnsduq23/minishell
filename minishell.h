/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:41:12 by junykim           #+#    #+#             */
/*   Updated: 2022/12/28 17:42:02 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>

typedef enum e_cmd
{
	DOUBLE_PIPE,
	DOUBLE_AMPER,
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
}	t_shell;

#endif
