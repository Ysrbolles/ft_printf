/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:49:21 by ybolles           #+#    #+#             */
/*   Updated: 2019/11/23 17:25:16 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags			ft_check_flags2(const char *format, va_list ap, t_flags flags)
{
	if ((FORM1 == 'l' || FORM1 == 'L') && FORM2 == 'f')
	{
		if (FORM1 == 'l')
			flags = ft_print_double(flags, va_arg(ap, double));
		else if (FORM1 == 'L')
			flags = ft_print_ldouble(flags, va_arg(ap, long double));
		CNT += 2;
	}
	else if (FORM1 == 'l' && ft_strchr(flags.flg1, FORM2))
	{
		if (FORM2 == 'd' || FORM2 == 'i')
			flags = ft_print_long_di(flags, va_arg(ap, long int));
		if (FORM2 == 'x' || FORM2 == 'X' || FORM2 == 'o' || FORM2 == 'u')
			flags = ft_print_ulong(flags, FORM2, va_arg(ap, unsigned long int));
		CNT += 2;
	}
	else
		flags = ft_check_flags3(format, ap, flags);
	return (flags);
}

t_flags			ft_check_flags3(const char *format, va_list ap, t_flags flags)
{
	if (FORM1 == 'l' && FORM2 == 'l' && ft_strchr(flags.flg1, FORM3))
	{
		if (FORM3 == 'x' || FORM3 == 'X' || FORM3 == 'o' || FORM3 == 'u')
			flags = ft_print_ptr(flags, FORM3, (va_arg(ap, ULLINT)));
		if (FORM3 == 'i' || FORM3 == 'd')
			flags = ft_print_long_long_di(flags, va_arg(ap, long long int));
		CNT += 3;
	}
	else if (FORM1 == 'h' && ft_strchr(flags.flg1, FORM2))
	{
		if (FORM2 == 'd' || FORM2 == 'i')
			flags = ft_print_short_di(flags, (short int)(va_arg(ap, int)));
		if (FORM2 == 'x' || FORM2 == 'X' || FORM2 == 'o' || FORM2 == 'u')
			flags = ft_print_ushort(flags, FORM2, (USINT)(va_arg(ap, UINT)));
		CNT += 2;
	}
	else if (FORM1 == 'h' && FORM2 == 'h' && ft_strchr(flags.flg1, FORM3))
	{
		if (FORM3 == 'd' || FORM3 == 'i')
			flags = ft_print_schar_di(flags, (char)(va_arg(ap, int)));
		if (FORM3 == 'x' || FORM3 == 'X' || FORM3 == 'o' || FORM3 == 'u')
			flags = ft_print_uchar(flags, FORM3, (UCHAR)((va_arg(ap, UINT))));
		CNT += 3;
	}
	return (flags);
}
