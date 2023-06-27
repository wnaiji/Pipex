/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:48:56 by wnaiji            #+#    #+#             */
/*   Updated: 2022/12/05 18:54:42 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printnbr(int nb);
int		ft_printnbr_base(unsigned int nb, char *base);
int		ft_print_unsignednbr(unsigned int nb);
int		ft_lower_or_up_case(unsigned int nb, char x);
int		ft_printptr(unsigned long long nb, char *base);
int		ft_printf(const char *str, ...);

size_t	ft_strlen(const char *str);

#endif
