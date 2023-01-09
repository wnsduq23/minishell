/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:20:03 by junykim           #+#    #+#             */
/*   Updated: 2023/01/08 21:46:13 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] == NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**sort_env(char **dest, t_shell *shell)
{
	char	*temp;
	int		i;

	dest = ft_calloc(ft_destlen(shell->env) + 1, sizeof(char *));
	i = -1;
	while (shell->env[++i])
		dest[i] = ft_strdup(shell->env[i]);
	dest[i] = NULL;
	i = 0;
	while (dest[i])
	{
		if (dest[i + 1] == NULL)
			break ;
		if (ft_strncmp(dest[i], dest[i + 1], 1) > 0)
		{
			temp = ft_strdup(dest[i]);
			dest[i] = ft_strdup(dest[i + 1]);
			dest[i + 1] = ft_strdup(temp);
			i = 0;
		}
		else
			i++;
	}
	return (dest);
}

void	display_export(t_shell *shell)
{
	int		i;
	char	**split;
	char	*temp;
	char	**dest;

	dest = NULL;
	dest = sort_env(dest, shell);
	i = -1;
	while (dest[++i])
	{
		if (ft_strchr(dest[i], '='))
		{
			// 이거 gnl 에서 strjoin 했던거 지우는 거 말하는 듯 ?
			split = ft_split(dest[i], '=');
			temp = ft_strjoin("=\"", split[1]);
			temp = ft_strjoin_free_s1(temp, "\"");
			temp = ft_strjoin_free_s2(split[0], temp);
			dest[i] = ft_strjoin_free_s2("declare -x ", temp);
		}
		else
			dest[i] = ft_strjoin_free_s2("declare -x ", dest[i]);
		ft_putendl_fd(dest[i], 1);
	}
	ft_free_split(split);
	ft_free_split(dest);
}

char	**ft_addline(char **env, char *token)
{
	int		i;
	char	*new_env;
	char	**dest;

	i = 0;
	while (env[i] != NULL)
		i++;
	new_env = ft_strjoin(env[i], token);
	// error 처리 해야하나  ?
	ft_strjoin_free(env[i]);
	dest = ft_calloc(i + 1, sizeof(char *));
}
