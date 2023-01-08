/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:39:08 by junykim           #+#    #+#             */
/*   Updated: 2023/01/08 20:26:04 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_equal(char *token)
{
	int	j;
	int	equal;

	equal = 0;
	j = -1;
	while (token[++j])
	{
		if (!ft_isalpha(token[0]) && !(token[0] == '_'))
			return (return_error_export("export: `", token,
					"': not a valid identifier", 1));
		if (token[j] == '=')
			equal++;
	}
	return (equal);
}

int	check_token(char *token)
{
	int		j;
	char	**split;

	split = ft_split(token, '=');
	j = 0;
	while (split[0][j])
	{
		if (!ft_isalpha(split[0][0]) && !(split[0][0] == '_'))
			return (return_error_export("export: `", split[0],
					"': not a valid identifier", 1));
		if (ft_isalnum(split[0][j]) || split[0][j] == '_' || split[0][j] == '='
			|| ft_isspace(split[0][j]))
			j++;
		else
			return (return_error_export("export: `", split[0],
					"': not a valid identifier", 1));
	}
	ft_free_split(split);
	return (0);
}

void	replace_exist_line(char *token, t_shell *shell)
{
	char	**split;
	int		i;
	char	*temp;

	temp = ft_strdup(token);
	split = ft_split(temp, '=');
	i = find_in_env(shell, split[0]);
	if (is_in_env(shell, split[0]))
		shell->env[i] = ft_strdup(temp);
	else
		shell->env = ft_addline(shell->env, temp);
	ft_free_split(split);
}

void	ft_export(t_tree *node, t_token *tok, t_shell *shell)
{
	int		i;
	int		check;

	if (node->token[1])
	{
		i = 0;
		check = 0;
		while (node->token[++i] != NULL)
		{
			check = check_token(node->token[i]);
			if (check == 0 && count_equal(node->token[i]) > 0)
				replace_exist_line(node->token[i], shell);
			else if (check == 0 && count_equal(node->token[i]) == 0
				&& !is_in_env(data, node->token[i]))
				shell->env = ft_addline(shell->env, node->token[i]);
		}
	}
	else
		display_export(data);
}
