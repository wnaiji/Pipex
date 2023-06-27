/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:39 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/27 11:01:58 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_fd(char *file1)
{
	int	fd;

	fd = open(file1, O_DIRECTORY);
	if (fd > 0)
	{
		ft_printf("Error: This is a directory\n");
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

/*void	parsing_cmd(char *cmd1, char *cmd2)
{
	char	**split1;
	char	**split2;

	split1 = ft_split(cmd1, ' ');
	split2 = ft_split(cmd2, ' ');
	if (access(split1[0], X_OK) < 0)
		perror("Error: cmd1 is not executable\n");
}*/

void	pipex(char *file1, char *cmd1, char *cmd2, char *file2)
{
	int		fd;
	int		i;
	pid_t	id;
	(void)cmd1;
	(void)cmd2;
	(void)file2;

	i = 0;
	fd = open_fd(file1);
	id = fork();
	if (id < 0)
		perror("Error: fork\n");
	if (id == 0)
		ft_printf("fils\n");
	else
		ft_printf("pere\n");

}

int	main(int argc, char **argv)
{
	if (argc == 5)
		pipex(argv[1], argv[2], argv[3], argv[4]);
	else
	{
		ft_printf("Error: The number of argument is not correct\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
