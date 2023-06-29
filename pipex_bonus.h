/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:30:41 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/29 16:37:37 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	char	**cmd;
	char	**env;
	int		fd_in;
	int		fd_out;
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		nb;
}	t_arg;

//Parsing des cmd et file:
//parsing.c
char	**parsing_cmd(char *cmd1);
char	**ft_envp(char **envp);
int		open_fd(char *file1);

//outils:
//utils.c
void	ft_free(char **str);
void	ft_close(t_arg arg);
void	ft_error(char *str);

#endif
