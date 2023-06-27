/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower_or_up_case.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:03:21 by wnaiji            #+#    #+#             */
/*   Updated: 2022/12/05 17:26:47 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lower_or_up_case(unsigned int nb, char x)
{
	int	size;

	size = 0;
	if (x == 'x')
	{
		size = ft_printnbr_base(nb, "0123456789abcdef");
		return (size);
	}
	else if (x == 'X')
	{
		size = ft_printnbr_base(nb, "0123456789ABCDEF");
		return (size);
	}
	else
		return (size);
}
