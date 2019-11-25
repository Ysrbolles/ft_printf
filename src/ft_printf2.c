/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:06:49 by ybolles           #+#    #+#             */
/*   Updated: 2019/11/24 18:47:15 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_flags		flags;
	va_list		ap;

	flags = ft_flags();
	va_start(ap, format);
	while (format[CNT])
	{
		if (format[CNT] == '%')
			flags = ft_read_flag(format, ap, flags);
		else
		{
			ft_putchar(format[CNT]);
			RTN++;
		}
		CNT++;
	}
	va_end(ap);
	return (RTN);
}

t_flags		ft_flags(void)
{
	t_flags flags;

	flags.flg0 = "csp%";
	flags.flg1 = "diouxX";
	flags.flg2 = "f";
	flags.flg0_0 = "hlL";
	flags.flgx = "#+-0123456789.";
	flags.cnt = 0;
	flags.nbret = 0;
	flags.prec = 0;
	flags.isprec = 0;
	flags.nbr1 = 0;
	flags.nbr2 = 0;
	flags.isnb2 = 0;
	flags.sgn = 0;
	flags.spc = 0;
	flags.is0 = 0;
	flags.hash = 0;
	return (flags);
}

t_flags		ft_print_flags(t_flags flags, char c, unsigned int flag)
{
	char	*str;
	int		len;

	if (c == 'o')
		str = ft_to_octal(flag);
	if (c == 'x' || c == 'X')
		str = ft_to_hexa(flag, c);
	if (c == 'u')
		str = ft_unsigned(flag);
	len = ft_strlen(str);
	if (flags.hash && c == 'o' && flags.nbr2 <= len && str[0] != '0')
		flags.nbr2 = len + 1;
	else if (flags.hash && c == 'o' && flags.nbr2 == 0 && str[0] == '0')
		flags.nbr2++;
	flags = print_di(flags, str, ft_strlen(str), c);
	free(str);
	return (flags);
}

t_flags		ft_print_decimal(t_flags flags, char c, int flag)
{
	char *str;

	if (c == 'd' || c == 'i')
	{
		str = ft_itoa(flag);
		flags = print_di(flags, str, ft_strlen(str), c);
		free(str);
	}
	if (c == 'c')
		flags = print_c(flags, flag);
	return (flags);
}

t_flags		ft_print_ptr(t_flags flags, char c, unsigned long long int flag)
{
	char	*str;
	int		len;

	if (c == 'p' || c == 'x' || c == 'X')
		str = ft_ptr(c, flag);
	if (c == 'o')
		str = ft_long_long_octa(flag);
	if (c == 'u')
		str = ft_long_long_u(flag);
	len = ft_strlen(str);
	if (flags.hash && c == 'o' && flags.nbr2 <= len && str[0] != '0')
		flags.nbr2 = len + 1;
	flags = print_di(flags, str, len, c);
	free(str);
	return (flags);
}
