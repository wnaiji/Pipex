/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walidnaiji <walidnaiji@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:15:59 by wnaiji            #+#    #+#             */
/*   Updated: 2023/07/01 08:42:06 by walidnaiji       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(int argc, char **argv, t_arg arg)
{
	char	*str;

	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		str = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(str, argv[2], ft_strlen(argv[2])))
			break;
		ft_putstr_fd(str, arg.fd_in);
		free(str);
	}
	free(str);
	close(arg.fd_in);
	arg.fd_in = open(".here_doc", O_RDONLY);
	pipex(argc, argv, arg);
	unlink(".here_doc");
}
