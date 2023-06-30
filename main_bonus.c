/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:04:15 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/30 13:48:42 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	whild_one(t_arg arg)
{
	int		i;
	char	*str;

	i = 0;
	dup2(arg.fd_in, STDIN_FILENO);
	dup2(arg.fd[1], STDOUT_FILENO);
	ft_close(arg);
	while (arg.env[i])
	{
		str = ft_ft_strjoin(arg.env[i], arg.cmd1[0]);
		if (execve(arg.cmd1[0], arg.cmd1, arg.env) == -1)
		{
			if (access(str, X_OK) == 0)
			{
				execve(str, arg.cmd1, arg.env);
				ft_error("Erreur: execve\n");
			}
			free(str);
			i++;
		}
	}
	ft_printf("command not found: %s\n", arg.cmd1[0]);
	exit(EXIT_FAILURE);
}

void	whild(t_arg arg, char **argv, int argc, int nb)
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
		dup2(arg.fd[0], STDIN_FILENO);
		dup2(arg.fd[1], STDOUT_FILENO);
		ft_close(arg);
		arg.cmd1 = parsing_cmd(argv[nb]);
		while (arg.env[i])
		{
			str = ft_ft_strjoin(arg.env[i], arg.cmd[0]);
			if (execve(arg.cmd[0], arg.cmd, arg.env) == -1)
			{
				if (access(str, X_OK) == 0)
				{
					execve(str, arg.cmd, arg.env);
					ft_error("Error: execve\n");
				}
				free(str);
				i++;
			}
		}
		ft_printf("bash: %s: command not found\n", arg.cmd[0]);
		exit(EXIT_FAILURE);
	}
	waitpid(pid, NULL, 0);
	if (nb < argc - 3)
	{
		nb++;
		whild(arg, argv, argc, nb);
	}
}

void	whild_two(t_arg arg)
{
	int		i;
	char	*str;

	i = 0;
	dup2(arg.fd[0], STDIN_FILENO);
	dup2(arg.fd_out, STDOUT_FILENO);
	ft_close(arg);
	while (arg.env[i])
	{
		str = ft_ft_strjoin(arg.env[i], arg.cmd2[0]);
		if (execve(arg.cmd2[0], arg.cmd2, arg.env) == -1)
		{
			if (access(str, X_OK) == 0)
			{
				execve(str, arg.cmd2, arg.env);
				ft_error("Erreur: execve\n");
			}
			free(str);
			i++;
		}
	}
	ft_printf("command not found: %s\n", arg.cmd2[0]);
	exit(EXIT_FAILURE);
}

void	pipex(int argc, char **argv, char **envp, t_arg arg)
{
	(void)envp;
	if (pipe(arg.fd) == -1)
		ft_error("Error: pipe\n");
	arg.pid1 = fork();
	if (arg.pid1 < 0)
		ft_error("Error: fork pid1\n");
	if (arg.pid1 == 0)
		whild_one(arg);
	waitpid(arg.pid1, NULL, WNOHANG);
	if (argc > 5)
		whild(arg, argv, argc, arg.nb);
	arg.pid2 = fork();
	if (arg.pid2 < 0)
		ft_error("Error: fork pid2\n");
	if (arg.pid2 == 0)
		whild_two(arg);
	ft_close(arg);
	waitpid(arg.pid2, NULL, WNOHANG);
	ft_free(arg.env);
	ft_free(arg.cmd1);
	ft_free(arg.cmd2);
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	arg;

	arg.cmd1 = NULL;
	if (!ft_strncmp(argv[1], "here_doc", 9))
	{
		arg = init_arg_here_doc(argc, argv, envp, arg);
		here_doc(argc, argv, envp, arg);
	}
	else if (argc > 4)
	{
		arg = init_arg_pipex(argc, argv, envp, arg);
		pipex(argc, argv, envp, arg);
	}
	else
	{
		ft_printf("Error: The number of argument is not correct\n");
		exit(EXIT_FAILURE);
	}
	system("leaks pipex");
	//system("lsof -c pipex");
	return (0);
}

