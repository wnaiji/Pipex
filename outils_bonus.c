/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walidnaiji <walidnaiji@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:03:03 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/28 21:32:25 by walidnaiji       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_close(t_arg arg)
{
	close(arg.fd[0]);
	close(arg.fd[1]);
	close(arg.fd_in);
	close(arg.fd_out);
}

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
