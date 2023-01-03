/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:31:24 by hwichoi           #+#    #+#             */
/*   Updated: 2023/01/03 22:22:49 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include "../minishell.h"
# include "../libft/libft.h"

// main_utils.c

int		envp_copy(char **envp, t_shell *shell);
void	print_err(char c);
void	free_all(t_shell *shell);

// tokenize.c

t_token	*quotes_div(t_token *token);
t_token	*tokenize(char *line);
t_token	*pipe_div(t_token *token);
t_token	*redir_div(t_token *token);
t_token	*space_div(t_token *token);

// tokenize_utils.c

void	clear_token(t_token **token);
t_token	*new_token(char *content);
t_token	*first_token(t_token *token);
t_token	*token_div(t_token *token, int size);
void	div_error(char c, t_token *token);

// tokenize_utils2.c

void	show_tokens(t_token *token);
t_token	*del_prev(t_token *token);

#endif
