/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:07:59 by ybolles           #+#    #+#             */
/*   Updated: 2019/11/23 17:24:51 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags		ft_print_long_long_di(t_flags flags, long long int flag)
{
	char	*str;

	str = ft_long_long_di(flag);
	flags = print_di(flags, str, ft_strlen(str), 'd');
	free(str);
	return (flags);
}

t_flags		ft_print_long_di(t_flags flags, long int flag)
{
	char	*str;

	str = ft_convert_long_di(flag);
	flags = print_di(flags, str, ft_strlen(str), 'd');
	free(str);
	return (flags);
}

t_flags		ft_print_ulong(t_flags flags, char c, unsigned long int flag)
{
	char	*str;
	int		len;

	if (c == 'x' || c == 'X')
		str = ft_convert_ulong_xx(c, flag);
	if (c == 'o')
		str = ft_cnvert_ulong_o(flag);
	if (c == 'u')
		str = ft_convert_ulong_u(flag);
	len = ft_strlen(str);
	if (flags.hash && c == 'o' && flags.nbr2 <= len && str[0] != '0')
		flags.nbr2 = len + 1;
	flags = print_di(flags, str, len, c);
	free(str);
	return (flags);
}

t_flags		ft_print_short_di(t_flags flags, short int flag)
{
	char	*str;

	str = ft_convert_short_di(flag);
	flags = print_di(flags, str, ft_strlen(str), 'd');
	free(str);
	return (flags);
}

t_flags		ft_print_ushort(t_flags flags, char c, unsigned short int flag)
{
	char	*str;
	int		len;

	if (c == 'x' || c == 'X')
		str = ft_convert_ushort_xx(c, flag);
	if (c == 'o')
		str = ft_convert_ushort_o(flag);
	if (c == 'u')
		str = ft_convert_ushort_u(flag);
	len = ft_strlen(str);
	if (flags.hash && c == 'o' && flags.nbr2 <= len && str[0] != '0')
		flags.nbr2 = len + 1;
	flags = print_di(flags, str, len, c);
	free(str);
	return (flags);
}
