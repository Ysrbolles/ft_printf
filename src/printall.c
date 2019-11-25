/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:36:31 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/24 18:31:02 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags		print_di3(t_flags flags, char *str, char c)
{
	if (str[0] != '-')
		RTN = print_space(flags, flags.spc, ' ');
	if (c == 'p')
		flags = ft_print_has_xx(flags, c);
	ft_putstr(str);
	return (flags);
}

t_flags		print_di2(t_flags flags, char *str, int len, int cnt)
{
	if (len)
		ft_putstr(str);
	if (flags.sgn && flags.nbr2 >= len)
		RTN = print_space(flags, flags.nbr1 - (flags.nbr2 + cnt), ' ');
	else if (flags.sgn && flags.nbr2 < len)
		RTN = print_space(flags, flags.nbr1 - (len + cnt), ' ');
	return (flags);
}

t_flags		print_di1(t_flags flags, char *str, int cnt, char c)
{
	int len;

	len = ft_strlen(str);
	flags.spc = flags.prec || str[0] == '-' ? 0 : flags.spc;
	RTN = print_space(flags, flags.spc, ' ');
	flags.prec = str[0] == '-' || (c != 'd' && c != 'i') ? 0 : flags.prec;
	cnt = str[0] == '-' && !flags.is0 ? cnt + 1 : cnt;
	if (flags.is0)
		flags.nbr2 = flags.spc || flags.prec ? flags.nbr2 - 1 : flags.nbr2;
	flags.nbr1 = flags.spc || flags.prec ? flags.nbr1 - 1 : flags.nbr1;
	if (str[0] == '0' && !flags.is0 && !flags.nbr2 && !flags.isnb2)
		len--;
	flags.nbr1 = !len && c == 'p' ? flags.nbr1 + 1 : flags.nbr1;
	if (!flags.sgn && flags.nbr2 >= len)
		RTN = print_space(flags, flags.nbr1 - (flags.nbr2 + cnt), ' ');
	else if (!flags.sgn && flags.nbr2 < len)
		RTN = print_space(flags, flags.nbr1 - len, ' ');
	len = str[0] == '-' && !flags.is0 ? len - 1 : len;
	RTN = str[0] == '-' && !flags.is0 ? RTN + 1 : RTN;
	if (str[0] == '-')
		print_space(flags, 1, '-');
	RTN = print_space(flags, flags.prec, '+');
	if (cnt && ((flags.hash && (c == 'x' || c == 'X')) || c == 'p'))
		flags = ft_print_has_xx(flags, c);
	return (flags);
}

t_flags		print_di(t_flags flags, char *str, int len, char c)
{
	int cnt;

	cnt = 0;
	if (flags.isprec)
	{
		if ((str[0] != '0' && flags.hash && (c == 'x' || c == 'X')) || c == 'p')
		{
			FNB1 = flags.nbr2 < len && !flags.sgn ? FNB1 - 2 : FNB1 - 1;
			flags.nbr2 = flags.is0 ? flags.nbr2 - 2 : flags.nbr2;
			cnt++;
		}
		flags = print_di1(flags, str, cnt, c);
		cnt = str[0] == '-' && !flags.is0 ? cnt + 1 : cnt;
		len = str[0] == '0' && !flags.is0 && !flags.nbr2 &&
			!flags.isnb2 ? len - 1 : len;
		len = str[0] == '-' && !flags.is0 ? len - 1 : len;
		if (flags.nbr2 > len)
			RTN = print_space(flags, flags.nbr2 - len, '0');
		str = str[0] == '-' ? str + 1 : str;
		flags = print_di2(flags, str, len, cnt);
	}
	else
		flags = print_di3(flags, str, c);
	RTN += len;
	return (ft_reset_precision(flags));
}

t_flags		print_c(t_flags flags, char c)
{
	if (!flags.sgn)
		RTN = print_space(flags, flags.nbr1 - 1, ' ');
	ft_putchar(c);
	if (flags.sgn)
		RTN = print_space(flags, flags.nbr1 - 1, ' ');
	RTN++;
	flags = ft_reset_precision(flags);
	return (flags);
}
