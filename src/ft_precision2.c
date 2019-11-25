/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 23:00:17 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/24 19:32:00 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags		ft_get_prec_c(t_flags flags, char *sflg)
{
	int cnt;

	cnt = 0;
	flags.sgn = ft_strchr(sflg, '-') ? 1 : 0;
	while (sflg[cnt] && !ft_isdigit(sflg[cnt]) && sflg[cnt] != '.')
		cnt++;
	flags.nbr1 = ft_atoi(&sflg[cnt]);
	free(sflg);
	return (flags);
}

t_flags		ft_get_prec_float(t_flags flags, char *sflg)
{
	int cnt;

	cnt = 0;
	flags.sgn = ft_strchr(sflg, '-') ? 1 : 0;
	flags.prec = ft_strchr(sflg, '+') ? 1 : 0;
	while (sflg[cnt] && !ft_isdigit(sflg[cnt]) && sflg[cnt] != '.')
		cnt++;
	flags.is0 = sflg[cnt] == '0' && !flags.sgn ? 1 : 0;
	if (sflg[cnt] != '.')
		flags.nbr1 = ft_atoi(&sflg[cnt]);
	while (sflg[cnt] && sflg[cnt] != '.')
		cnt++;
	if (sflg[cnt] == '.')
		flags.nbr2 = ft_atoi(&sflg[cnt + 1]);
	else
		flags.nbr2 = -1;
	flags.isprec = 1;
	free(sflg);
	return (flags);
}

t_flags		ft_read_prec(const char *format, t_flags flags, char *sflg, int cnt)
{
	while (ft_strchr(flags.flgx, FORM1))
		CNT++;
	if (FORM1 == ' ')
		flags = ft_skip_space(format, flags);
	if (ft_strchr(flags.flg1, FORM1) || ft_strchr(flags.flg0, FORM1) ||
			ft_many_flags(format, flags) || FORM1 == 'f')
	{
		SAFE(sflg = (char *)malloc(sizeof(char) * ((CNT - cnt) + 1)));
		sflg[CNT - cnt] = '\0';
		CNT = cnt;
		while (ft_strchr(flags.flgx, FORM1))
			sflg[(CNT++) - cnt] = FORM1;
		if (FORM1 == ' ')
			flags = ft_skip_space(format, flags);
		if (ft_strchr(flags.flg1, FORM1) || ft_strchr(flags.flg0, FORM1) ||
				FORM1 == 'f')
			flags = ft_get_precision(flags, sflg, FORM1);
		else if (ft_many_flags(format, flags) == 1)
			flags = ft_get_precision(flags, sflg, FORM2);
		else if (ft_many_flags(format, flags) == 2)
			flags = ft_get_precision(flags, sflg, FORM3);
	}
	else
		CNT = cnt;
	return (flags);
}

t_flags		ft_get_precision(t_flags flags, char *sflg, char c)
{
	if (c == 's' || c == '%')
		flags = ft_get_precision_s(flags, sflg, c);
	else if (ft_strchr(flags.flg1, c) || c == 'p')
		flags = ft_get_prec_di(flags, sflg, 0);
	else if (c == 'c')
		flags = ft_get_prec_c(flags, sflg);
	else if (c == 'f')
		flags = ft_get_prec_float(flags, sflg);
	return (flags);
}
