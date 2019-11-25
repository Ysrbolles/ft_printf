/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:09:51 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/23 17:24:43 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags		ft_print_str(t_flags flags, char *str, char c)
{
	if (!str)
		str = "(null)";
	flags = print_s(flags, str, ft_strlen(str), c);
	return (flags);
}

t_flags		ft_print_uchar(t_flags flags, char c, unsigned char flag)
{
	char	*str;
	int		len;

	if (c == 'x' || c == 'X')
		str = ft_convert_uchar_xx(c, flag);
	if (c == 'o')
		str = ft_convert_uchar_o(flag);
	if (c == 'u')
		str = ft_convert_uchar_u(flag);
	len = ft_strlen(str);
	if (flags.hash && c == 'o' && flags.nbr2 <= len && str[0] != '0')
		flags.nbr2 = len + 1;
	flags = print_di(flags, str, len, c);
	free(str);
	return (flags);
}

t_flags		ft_print_schar_di(t_flags flags, signed char flag)
{
	char	*str;

	str = ft_convert_schar_di(flag);
	flags = print_di(flags, str, ft_strlen(str), 'd');
	free(str);
	return (flags);
}

t_flags		ft_print_double(t_flags flags, double flag)
{
	char	**tab;
	char	*str;

	tab = ft_convert_double(flag);
	str = tab[0][0] == '-' ? tab[0] + 1 : tab[0];
	flags = print_double(flags, tab, ft_strlen(tab[0]), str);
	ft_free_tab(tab);
	return (flags);
}

t_flags		ft_print_ldouble(t_flags flags, long double flag)
{
	char	**tab;
	char	*str;

	tab = ft_convert_ldouble(flag);
	str = tab[0][0] == '-' ? tab[0] + 1 : tab[0];
	flags = print_double(flags, tab, ft_strlen(tab[0]), str);
	ft_free_tab(tab);
	return (flags);
}
