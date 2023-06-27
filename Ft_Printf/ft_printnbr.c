/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:05:15 by wnaiji            #+#    #+#             */
/*   Updated: 2022/12/05 17:34:06 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size_int(int nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (1);
	if (nb == -2147483648)
		return (11);
	else if (nb < 0)
	{
		size++;
		nb *= -1;
	}
	while (nb >= 1)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

int	ft_printnbr(int nb)
{
	int	size;

	size = ft_size_int(nb);
	if (nb == -2147483648)
	{
		ft_printstr("-2");
		nb = 147483648;
	}
	else if (nb < 0)
	{
		ft_printchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_printnbr(nb / 10);
		ft_printnbr(nb % 10);
	}
	if (nb <= 9)
		ft_printchar(nb + '0');
	return (size);
}
