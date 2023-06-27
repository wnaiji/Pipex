/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsignednbr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:38:09 by wnaiji            #+#    #+#             */
/*   Updated: 2022/12/05 19:01:32 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_size_int(size_t nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb >= 1)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

int	ft_print_unsignednbr(unsigned int nb)
{
	size_t	size;

	size = ft_size_int(nb);
	if (nb > 9)
	{
		ft_printnbr(nb / 10);
		ft_printnbr(nb % 10);
	}
	if (nb <= 9)
		ft_printchar(nb + '0');
	return (size);
}
