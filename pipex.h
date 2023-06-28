/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walidnaiji <walidnaiji@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:08:53 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/28 17:54:21 by walidnaiji       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "Libft/libft.h"
# include "Ft_Printf/ft_printf.h"
# include "Get_Next_Line/get_next_line.h"

typedef struct s_arg
{
	char	**cmd1;
	char	**cmd2;
	char	**env;
	int		fd_in;
	int		fd_out;
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
}	t_arg;

//Parsing des cmd et file:
//parsing.c
char	**parsing_cmd(char *cmd1);
char	**ft_envp(char **envp);
int		open_fd(char *file1);

#endif
