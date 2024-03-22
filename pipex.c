/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:41:27 by gd-auria          #+#    #+#             */
/*   Updated: 2024/03/21 19:21:55 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ch_proc(char **argv, char **envp, int *fd)
{
	int	file1;

	file1 = open(argv[1], O_RDONLY, 0777);
	if (file1 == -1)
		perror("A PROBLEM OCCURED WITH FILE1");
	dup2(fd[1], STDOUT_FILENO);
	dup2(file1, STDIN_FILENO);
	close(fd[0]);
	myexec(argv[2], envp);
}

void	par_proc(char **argv, char **envp, int *fd)
{
	int	file2;

	file2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (file2 == -1)
		perror("A PROBLEM OCCURED WITH FILE2");
	dup2(fd[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(fd[1]);
	myexec(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc != 5)
		(perror("WRONG ARGC NUMBER"));
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			(perror("PIPE ERROR"));
		pid1 = fork();
		if (pid1 == -1)
			(perror("PID ERROR"));
		if (pid1 == 0)
			ch_proc(argv, envp, ((int *)fd));
		waitpid(pid1, NULL, 0);
		par_proc(argv, envp, ((int *)fd));
	}
	else
		exit(0);
}
