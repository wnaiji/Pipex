/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walidnaiji <walidnaiji@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:39 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/28 12:10:04 by walidnaiji       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_printf("%s\n", str[i]);
		i++;
	}
}

void	pipex(char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		i;
	t_arg	arg;
	char	*str;

	arg.cmd1 = parsing_cmd(argv[2]);
	arg.cmd2 = parsing_cmd(argv[3]);
	arg.env = ft_envp(envp);
	arg.fd_in = open_fd(argv[1]);
	arg.fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	pid1 = fork();
	i = 0;
	if (pid1 < 0)
	{
		perror("Error: fork pid1\n");
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
	{
		perror("Error: pipe\n");
		exit(EXIT_FAILURE);
	if (pid1 == 0)
	{
		while (arg.env[i])
		{
			str = ft_ft_strjoin(arg.env[i], arg.cmd1[0]);
			if (access(str, X_OK) == 0)
			{
				close(fd[0]);
				dup2(arg.fd_in, STDIN_FILENO);
				close(arg.fd_in);
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
				execve(str, arg.cmd1, arg.env);
				perror("Erreur: execve\n");
				exit(EXIT_FAILURE);
			}
			free(str);
			i++;
		}
		exit(EXIT_SUCCESS);
	}
	pid2 = fork();
	if (pid2 < 0)
		perror("Error: fork pid2\n");
	if (pid2 == 0)
	{
		i = 0;
		while (arg.env[i])
		{
			str = ft_ft_strjoin(arg.env[i], arg.cmd2[0]);
			if (access(str, X_OK) == 0)
			{
				close(fd[1]);
				dup2(fd[0], STDIN_FILENO);
				close(fd[0]);
				dup2(arg.fd_out, STDOUT_FILENO);
				close(arg.fd_out);
				execve(str, arg.cmd2, arg.env);
				perror("Erreur: execve\n");
				exit(EXIT_FAILURE);
			}
			free(str);
			i++;
		}
		exit(EXIT_SUCCESS);
	}
	close(fd[0]);
	close(fd[1]);
	close(arg.fd_in);
	close(arg.fd_out);
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
