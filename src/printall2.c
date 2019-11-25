/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printall2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:02:34 by ybolles           #+#    #+#             */
/*   Updated: 2019/11/23 17:30:42 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags		ft_print_has_xx(t_flags flags, char c)
{
	if (c == 'x' || c == 'p')
		ft_putstr("0x");
	if (c == 'X')
		ft_putstr("0X");
	RTN += 2;
	return (flags);
}

int			print_space(t_flags flags, int len, char c)
{
	int cnt;

	cnt = 0;
	while (cnt++ < len)
	{
		ft_putchar(c);
		RTN++;
	}
	return (RTN);
}

t_flags		print_s(t_flags flags, char *str, int len, char c)
{
	int cnt;

	cnt = 0;
	if (c != '%')
		len = len >= flags.nbr2 && flags.isprec && flags.nbr2 >= 0 ?
			flags.nbr2 : len;
	if (flags.sgn == 1 && !flags.is0)
		RTN = print_space(flags, flags.nbr1 - len, ' ');
	if (flags.sgn == 1 && flags.is0)
		RTN = print_space(flags, flags.nbr1 - len, '0');
	while (cnt < len)
		ft_putchar(str[cnt++]);
	if (flags.sgn == -1)
		RTN = print_space(flags, flags.nbr1 - len, ' ');
	RTN += len;
	flags = ft_reset_precision(flags);
	return (flags);
}
