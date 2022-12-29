/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:15:48 by junykim           #+#    #+#             */
/*   Updated: 2022/12/28 17:17:16 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

 char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}
	

//TODO: : 잘못된 cmd인 경우 오류 출력만 하고 계속 수행한다.  
//WARN: : 

int	do_SC(char **paths, char *cmd)
{
	int	status;
	char	*a;

	a = get_cmd(paths, cmd);
	if (a == NULL)
	{
		perror();
		return (status); // 127 signal return 
	}
	execve(a, argv[],envp);
	return (status); // success
}

//XXX: : A || B if A fail, execute B
int	do_DP(t_tree *tree, char **paths, char *cmd)
{
	int	status;
	char	*a;

	if (tree->left->left->cmd == success) // A success
	{
		//B 수행 X
		return (status);
	}
	else
	{
		a = get_cmd(paths, cmd);
		if (a == NULL)
		{
			perror();
			return (status); // 127 signal return 
		}
		execve(a, argv[],envp); // av[]는 파싱부에서 자른 거 갖고오는거임
	}
	return (status);
}

//XXX: : A || B , if A is success, execute B
int	do_DA(t_tree *tree, char **paths, char *cmd)
{
	int	status;

	if (tree->left->left->cmd == FAIL) // A가 fail
	{
		//B 수행 X
		return (status);
	}
	else
	{
		a = get_cmd(paths, cmd);
		if (a == NULL)
		{
			perror();
			return (status); // 127 signal return 
		}
		execve(a, argv[],envp); // av[]는 파싱부에서 자른 거 갖고오는거임
	}
	return (status);
}

int	do_SP()
{
	fork(); 
	
}
