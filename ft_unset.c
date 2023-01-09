/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:38:03 by junykim           #+#    #+#             */
/*   Updated: 2023/01/08 21:51:42 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_tok_unset(char *token)
{
	int		j;

	j = 0;
	while (token[j])
	{
		if (!ft_isalpha(token[0]) && !(token[0] == '_'))
			return (return_error_export("unset: `", token,
					"': not a valid identifier", 1));
		if (ft_isalnum(token[j]) || token[j] == '_' || ft_isspace(token[j]))
			j++;
		else
			return (return_error_export("unset: `", token,
					"': not a valid identifier", 1));
	}
	return (0);
}

char	**feed_temp(t_shell *shell, char **temp)// 이름 바꾸기 
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (shell->env[i])
	{
		if (ft_strlen(shell->env[i]) == 0)
			i++;
		else
		{
			temp[j] = ft_strdup(shell->env[i]);
			j++;
			i++;
		}
	}
	temp[j] = NULL;
	return (temp);
}

int	ft_unset(t_shell *shell, char **token)
{
	int		i;
	char	**temp;
	int		j;

	temp = ft_calloc(sizeof(char *), (size_t)ft_destlen(shell->env));
	i = 0;
	while (token[++i])
	{
		if (!check_tok_unset(token[i]))
		{
			j = find_in_env(shell, token[i]);
			if (j <= ft_destlen(shell->env) && j >= 0)
			{
				if (shell->env[j])
				{
					shell->env[j] = ft_strdup("");
					shell->env = feed_temp(shell, temp);
				}
			}
			else
				return (-1);
		}
	}
	return (0);
}
