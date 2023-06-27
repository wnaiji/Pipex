/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:00:37 by wnaiji            #+#    #+#             */
/*   Updated: 2022/12/05 18:54:21 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversions(char c, va_list arg)
{
	int	i;

	i = 0;
	if (c == 'd')
		i = ft_printnbr(va_arg(arg, int));
	if (c == 'c')
		i = ft_printchar(va_arg(arg, int));
	if (c == 's')
		i = ft_printstr(va_arg(arg, char *));
	if (c == 'i')
		i = ft_printnbr(va_arg(arg, int));
	if (c == 'u')
		i = ft_print_unsignednbr(va_arg(arg, unsigned int));
	if (c == 'x')
		i = ft_lower_or_up_case(va_arg(arg, unsigned int), 'x');
	if (c == 'X')
		i = ft_lower_or_up_case(va_arg(arg, unsigned int), 'X');
	if (c == '%')
		i = ft_printchar('%');
	if (c == 'p')
	{
		ft_printstr("0x");
		i = ft_printptr(va_arg(arg, unsigned long long), "0123456789abcdef");
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	va_list	arg;

	i = 0;
	j = 0;
	va_start(arg, str);
	while (str[i])
	{
		while (str[i] == '%')
		{
			i++;
			j += ft_conversions(str[i++], arg);
			if (str[i] == '\0')
				return (j);
		}
		j += ft_printchar(str[i]);
		i++;
	}
	va_end(arg);
	return (j);
}
