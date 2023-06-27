/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:39 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/27 15:47:56 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		i;
	t_arg	arg;

	arg.cmd1 = parsing_cmd(argv[1]);
	arg.cmd2 = parsing_cmd(argv[2]);
	arg.env = ft_envp(envp);
	arg.fd = open_fd(argv[0]);
	pid1 = fork();
	i = 0;
	if (pid1 < 0)
		perror("Error: fork pid1\n");
	if (pipe(fd) == -1)
		perror("Error: pipe\n");
	if (pid1 == 0)
	{
		while (arg.env[i])
		{
			arg.cmd1[0] = ft_strjoin(arg.env[i], arg.cmd1[0]);
			if (access(arg.cmd1[0], X_OK) == 0)
			{
		ft_printf("je suis le fils pid1\n");
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				execve(arg.cmd1[0], arg.cmd1, arg.env);
			}
			i++;
		}
	}
	pid2 = fork();
	if (pid2 < 0)
		perror("Error: fork pid2\n");
	if (pid2 == 0)
	{
		while (arg.env[i])
		{
			arg.cmd2[0] = ft_strjoin(arg.env[i], arg.cmd2[0]);
			if (access(arg.cmd2[0], X_OK) == 0)
			{
		ft_printf("je suis le fils pid2\n");
				dup2(fd[0], STDIN_FILENO);
				close(fd[0]);
				close(fd[1]);
				execve(arg.cmd2[0], arg.cmd2, arg.env);
			}
		}
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
		pipex(argv, envp);
	else
	{
		ft_printf("Error: The number of argument is not correct\n");
		exit(EXIT_FAILURE);
	}
	//system("leaks pipex");
	return (0);
}
