/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:05:03 by ybolles           #+#    #+#             */
/*   Updated: 2019/11/23 17:29:53 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		**ft_convert_ldouble(long double num)
{
	char				**tab;
	unsigned long long	nbr;
	int					cnt;

	cnt = 0;
	SAFE(tab = (char **)malloc(sizeof(char *) * 2));
	tab[0] = ft_long_long_di((long long int)(num));
	if (num < 0 && tab[0][0] != '-')
		tab[0] = add_minus(tab[0]);
	num = num < 0 ? -num : num;
	nbr = (unsigned long long)(num);
	num -= nbr;
	SAFE(tab[1] = (char *)malloc(sizeof(char) * 21));
	while (cnt < 20)
	{
		num *= 10.0;
		nbr = (unsigned long long)(num);
		tab[1][cnt++] = nbr + '0';
		num -= nbr;
	}
	tab[1][cnt] = '\0';
	return (tab);
}

int			print_after_point(char *str, int nbr2)
{
	int cnt;

	cnt = 0;
	while (str[cnt] && cnt < nbr2)
		ft_putchar(str[cnt++]);
	return (cnt);
}

t_flags		print_double(t_flags flags, char **tab, int len, char *str)
{
	int		cnt;

	cnt = 0;
	flags.nbr2 = flags.nbr2 == -1 || !flags.isprec ? 6 : flags.nbr2;
	flags.nbr1 = flags.nbr2 ? flags.nbr1 - 1 : flags.nbr1;
	flags.spc = flags.prec || tab[0][0] == '-' ? 0 : flags.spc;
	flags.prec = tab[0][0] == '-' ? 0 : flags.prec;
	flags.nbr1 = flags.spc || flags.prec ? flags.nbr1 - 1 : flags.nbr1;
	RTN = print_space(flags, flags.spc, ' ');
	if (!flags.sgn && !flags.is0)
		RTN = print_space(flags, flags.nbr1 - (flags.nbr2 + len), ' ');
	if (tab[0][0] == '-')
		print_space(flags, 1, '-');
	RTN = print_space(flags, flags.prec, '+');
	if (flags.is0)
		RTN = print_space(flags, flags.nbr1 - (len + flags.nbr2), '0');
	ft_putstr(str);
	if (flags.nbr2)
		RTN = print_space(flags, 1, '.');
	cnt = print_after_point(tab[1], flags.nbr2);
	RTN = print_space(flags, flags.nbr2 - cnt, '0');
	if (flags.sgn)
		RTN = print_space(flags, flags.nbr1 - (flags.nbr2 + len), ' ');
	RTN += len + flags.nbr2;
	return (flags);
}
