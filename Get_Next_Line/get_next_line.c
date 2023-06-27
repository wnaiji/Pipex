/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:14:10 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/27 11:02:42 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_rest_line(char *rest, char *tmp)
{
	int		i;
	int		j;

	j = ft_strlen(tmp);
	i = 0;
	if (rest)
		free(rest);
	rest = NULL;
	if (ft_strchr(tmp, '\n') != NULL)
	{
		while (tmp[i] != '\n')
			i++;
	}
	if ((i == 0 && j < 2) || (ft_strchr(tmp, '\n') == NULL))
		return (NULL);
	rest = malloc(sizeof(char) * (j - i + 1));
	if (!rest)
		return (NULL);
	j = 0;
	while (tmp[i])
		rest[j++] = tmp[++i];
	rest[j] = '\0';
	return (rest);
}

static char	*ft_parsing_tmp(char *tmp)
{
	int		i;
	char	*gnl;

	i = 0;
	gnl = NULL;
	while (tmp[i] != '\n')
		i++;
	if (i == 0 && ft_strlen(tmp) < 2)
		return (tmp);
	gnl = malloc(sizeof(char) * (i + 2));
	if (!gnl)
		return (NULL);
	i = 0;
	while (tmp[i] != '\n')
	{
		gnl[i] = tmp[i];
		i++;
	}
	gnl[i] = '\n';
	gnl[i + 1] = '\0';
	free(tmp);
	return (gnl);
}

static char	*ft_join_rest_tmp(char **rest, char *tmp)
{
	char	*tmp2;

	tmp2 = ft_ft_strjoin(*rest, tmp);
	free(*rest);
	*rest = NULL;
	free(tmp);
	tmp = ft_ft_strdup(tmp2, 1);
	return (tmp);
}

void	ft_return_gnl(char *buf, char **rest, char **tmp, int i)
{
	if (!(*tmp) && !(buf[0] == '\0'))
		*tmp = ft_ft_strdup(buf, 0);
	else if (*tmp && i != 0)
		*tmp = ft_join_tmp_buf(*tmp, buf);
	if (*rest && (ft_strchr(*tmp, '\n') != NULL))
		*tmp = ft_join_rest_tmp(&(*rest), *tmp);
	else if (*rest && !(*tmp) && *rest[0] != '\0')
	{
		*tmp = ft_ft_strdup(*rest, 1);
		*rest = NULL;
	}
	if ((ft_strchr(*tmp, '\n') != NULL)
		|| (ft_strchr(*tmp, '\n') == NULL && i == 0))
	{
		if (*rest)
			*tmp = ft_join_rest_tmp(&(*rest), *tmp);
		if (ft_strchr(*tmp, '\n') == NULL && i == 0)
			return ;
		*rest = ft_rest_line(*rest, *tmp);
		*tmp = ft_parsing_tmp(*tmp);
		return ;
	}
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*rest;
	char		*tmp;
	int			i;

	i = 1;
	tmp = NULL;
	while (!(read(fd, 0, 0) < 0))
	{
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
		ft_return_gnl(buf, &rest, &tmp, i);
		if ((ft_strchr(tmp, '\n') != NULL)
			|| (ft_strchr(tmp, '\n') == NULL && i == 0))
			return (tmp);
	}
	if (rest)
	{
		free(rest);
		rest = NULL;
	}
	return (NULL);
}
