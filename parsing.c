/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walidnaiji <walidnaiji@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:21:58 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/28 10:14:08 by walidnaiji       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parsing_cmd(char *cmd1)
{
	char	**split;

	split = ft_split(cmd1, ' ');
	return (split);
}

char	**ft_envp(char **envp)
{
	int		i;
	char	*path;
	char	**env;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 4))
			path = ft_strdup(envp[i]);
		i++;
	}
	path = ft_strtrim(path, "PATH=");
	env = ft_split(path, ':');
	i = 0;
	while (env[i])
	{
		env[i] = ft_strjoin(env[i], "/");
		i++;
	}
	free(path);
	return (env);
}

int	open_fd(char *file1)
{
	int	fd;

	fd = open(file1, O_DIRECTORY);
	if (fd > 0)
	{
		ft_printf("Error: This is a directory\n");
		close(fd);
		exit(EXIT_FAILURE);
	}
	fd = open(file1, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: File is not open\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
