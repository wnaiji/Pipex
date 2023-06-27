/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:21:05 by wnaiji            #+#    #+#             */
/*   Updated: 2022/12/05 18:55:54 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long long nb, char *base)
{
	unsigned long long		len;
	unsigned long long		i;

	len = 0;
	if (!nb)
	{
		ft_printchar('0');
		return (3);
	}
	i = nb;
	if (nb > 15)
	{
		ft_printptr(nb / 16, base);
		ft_printptr(nb % 16, base);
	}
	if (nb <= 15)
		ft_printchar(base[nb]);
	if (i == 0)
		len++;
	while (i > 0)
	{
		i /= 16;
		len++;
	}
	return (len + 2);
}
