/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:41:40 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/27 10:58:54 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return ((char *)str + i);
	return (NULL);
}

char	*ft_ft_strdup(char *src, int j)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!(src))
		return (NULL);
	tmp = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!tmp)
		return (NULL);
	while ((src)[i])
	{
		tmp[i] = (src)[i];
		i++;
	}
	tmp[i] = '\0';
	if (j == 1)
	{
		free(src);
		src = NULL;
	}
	return (tmp);
}

char	*ft_ft_strjoin(char *s1, char *s2)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	tmp = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(tmp))
		return (NULL);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tmp[i + j] = s2[j];
		j++;
	}
	tmp[i + j] = '\0';
	return (tmp);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_join_tmp_buf(char *tmp, char *buf)
{
	char	*tmp2;

	tmp2 = ft_ft_strjoin(tmp, buf);
	free(tmp);
	tmp = ft_ft_strdup(tmp2, 1);
	return (tmp);
}
