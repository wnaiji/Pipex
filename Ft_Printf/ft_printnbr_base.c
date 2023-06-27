/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:42:28 by wnaiji            #+#    #+#             */
/*   Updated: 2022/12/05 17:32:21 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr_base(unsigned int nb, char *base)
{
	unsigned int	len_base;
	int				len;
	unsigned int	i;

	i = nb;
	len = 0;
	if (!base)
		return (0);
	len_base = ft_strlen(base);
	if (nb >= len_base)
	{
		ft_printnbr_base(nb / len_base, base);
		ft_printnbr_base(nb % len_base, base);
	}
	if (nb < len_base)
		ft_printchar(base[nb]);
	if (i == 0)
		len++;
	while (i > 0)
	{
		i /= 16;
		len++;
	}
	return (len);
}
