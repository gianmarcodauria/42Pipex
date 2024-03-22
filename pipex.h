/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:54:34 by gd-auria          #+#    #+#             */
/*   Updated: 2024/03/21 19:41:00 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"

void	ch_proc(char **argv, char **envp, int *fd);
void	par_proc(char **argv, char **envp, int *fd);
int		main(int argc, char **argv, char **envp);
char	*to_path(char *command, char **envp);
void	myexec(char *argv, char **envp);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	**ft_split(const char *s, char c);

#endif
