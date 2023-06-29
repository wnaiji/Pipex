/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:04:15 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/29 13:17:27 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	whild_one(t_arg arg)
{
	int		i;
	char	*str;

	i = 0;
	while (arg.env[i])
	{
		str = ft_ft_strjoin(arg.env[i], arg.cmd1[0]);
		if (access(str, X_OK) == 0)
		{
			dup2(arg.fd_in, STDIN_FILENO);
			dup2(arg.fd[1], STDOUT_FILENO);
			ft_close(arg);
			execve(str, arg.cmd1, arg.env);
			ft_error("Erreur: execve\n");
		}
		free(str);
		i++;
	}
	ft_printf("command not found: %s\n", arg.cmd1[0]);
	exit(EXIT_FAILURE);
}

void	whild(t_arg arg, char **argv, int nb)
{
	int		i;
	char	*str;
	pid_t	pid;

	i = 0;
	pid = fork();
	if (pid < 0)
		ft_error("Error: fork pid1\n");
	if (pid == 0)
	{
		while (arg.env[i])
		{
			str = ft_ft_strjoin(arg.env[i], arg.cmd2[0]);
			if (access(str, X_OK) == 0)
			{
				dup2(arg.fd[0], STDIN_FILENO);
				dup2(arg.fd[1], STDOUT_FILENO);
				ft_close(arg);
				execve(str, arg.cmd2, arg.env);
				ft_error("Erreur: execve\n");
			}
			free(str);
			i++;
		}
		ft_printf("command not found: %s\n", arg.cmd1[/////]);
		exit(EXIT_FAILURE);
	}
	waitpid(pid, NULL, 0);
	if (nb > 2)
		whild(arg, argc, argv, nb--)
}

void	whild_two(t_arg arg)
{
	int		i;
	char	*str;

	i = 0;
	while (arg.env[i])
	{
		str = ft_ft_strjoin(arg.env[i], arg.cmd2[0]);
		if (access(str, X_OK) == 0)
		{
			dup2(arg.fd[0], STDIN_FILENO);
			dup2(arg.fd_out, STDOUT_FILENO);
			ft_close(arg);
			execve(str, arg.cmd2, arg.env);
			ft_error("Erreur: execve\n");
		}
		free(str);
		i++;
	}
	ft_printf("command not found: %s\n", arg.cmd2[0]);
	exit(EXIT_FAILURE);
}

void	pipex(int argc, char **argv, char **envp)
{
	t_arg	arg;
(void)argc;
	arg.cmd1 = parsing_cmd(argv[2]);
	arg.cmd2 = parsing_cmd(argv[3]);
	arg.env = ft_envp(envp);
	arg.fd_in = open_fd(argv[1]);
	arg.fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipe(arg.fd) == -1)
		ft_error("Error: pipe\n");
	arg.pid1 = fork();
	if (arg.pid1 < 0)
		ft_error("Error: fork pid1\n");
	if (arg.pid1 == 0)
		whild_one(arg);
	waitpid(arg.pid1, NULL, 0);
	if (argc > 5)
		whild(t_arg arg, char **argv, int argc - 3);
	arg.pid2 = fork();
	if (arg.pid2 < 0)
		ft_error("Error: fork pid2\n");
	if (arg.pid2 == 0)
		whild_two(arg);
	ft_close(arg);
	waitpid(arg.pid2, NULL, 0);
	ft_free(arg.env);
	ft_free(arg.cmd1);
	ft_free(arg.cmd2);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc > 4)
		pipex(argc, argv, envp);
	else
	{
		ft_printf("Error: The number of argument is not correct\n");
		exit(EXIT_FAILURE);
	}
	//system("leaks pipex");
	return (0);
}

