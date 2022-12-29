/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:41:12 by junykim           #+#    #+#             */
/*   Updated: 2022/12/28 15:59:29 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// free, malloc
# include <stdlib.h>

// access
#include <unistd.h>

# include "libft/libft.h"

typedef enum e_cmd
{
	DOUBLE_PIPE,
	DOUBLE_AMPER,
	SINGLE_CMD,
	SINGLE_PIPE
}t_cmd;

// ================================
//			cmd1.c
// ================================
char	*get_cmd(char **paths, char *cmd);
#endif
