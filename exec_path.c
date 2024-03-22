/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:52:18 by gd-auria          #+#    #+#             */
/*   Updated: 2024/03/18 18:04:41 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*to_path(char *command, char **envp)
{
	char	**total_path;
	char	*my_path1;
	char	*my_path2;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	total_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (total_path[i])
	{
		my_path1 = ft_strjoin(total_path[i], "/");
		my_path2 = ft_strjoin(my_path1, command);
		free(my_path1);
		if (access(my_path2, F_OK) == 0)
			return (my_path2);
		free(my_path2);
		i++;
	}
	i = 0;
	while (total_path[i++])
		free(total_path[i]);
	free(total_path);
	return (0);
}

void	myexec(char *argv, char **envp)
{
	char	**command;
	char	*found_path;
	int		i;

	i = 0;
	command = ft_split(argv, ' ');
	found_path = to_path(command[0], envp);
	if (!found_path)
	{
		while (command[i])
		{
			free(command[i]);
			i++;
		}
		free(command);
		perror("FOUND PATH ERROR");
	}
	if (execve(found_path, command, envp) == -1)
		perror("SOMETHING WRONG DURING EXEC");
}
