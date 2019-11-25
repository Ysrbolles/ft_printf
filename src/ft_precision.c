/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:25:26 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/23 17:30:08 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags		ft_get_precision_s(t_flags flags, char *sflg, char c)
{
	int	cnt;

	cnt = 0;
	flags.nbr2 = -1;
	if (!ft_strchr(sflg, '-') && c == '%')
	{
		while (!ft_isdigit(sflg[cnt]))
			cnt++;
		if (sflg[cnt] == '0')
			flags.is0 = 1;
		cnt = 0;
	}
	while (sflg[cnt] && !ft_isdigit(sflg[cnt]) && sflg[cnt] != '.')
		cnt++;
	flags.nbr1 = ft_atoi(&sflg[cnt]);
	while (sflg[cnt] && sflg[cnt] != '.')
		cnt++;
	if (sflg[cnt] == '.')
		flags.nbr2 = ft_atoi(&sflg[cnt + 1]);
	flags.sgn = ft_strchr(sflg, '-') ? -1 : 1;
	free(sflg);
	flags.isprec = 1;
	return (flags);
}

char		*ft_get_hash(int *hash, char *str)
{
	char	*nstr;
	int		cnt;
	int		cnt1;

	cnt = ft_strlen(str);
	cnt1 = 0;
	SAFE(nstr = (char *)malloc(sizeof(char) * (cnt)));
	cnt = 0;
	while (str[cnt])
	{
		if (str[cnt] != '#')
			nstr[cnt1++] = str[cnt];
		cnt++;
	}
	nstr[cnt1] = '\0';
	free(str);
	str = nstr;
	*hash = 1;
	return (nstr);
}

t_flags		ft_get_prec_di(t_flags flags, char *sflg, int cnt)
{
	if (ft_strchr(sflg, '#'))
		sflg = ft_get_hash(&flags.hash, sflg);
	if (!ft_strchr(sflg, '.') && !ft_strchr(sflg, '-'))
	{
		while (sflg[cnt] && !ft_isdigit(sflg[cnt]))
			cnt++;
		flags.is0 = sflg[cnt] == '0' ? 1 : 0;
		cnt = 0;
	}
	if (!ft_strchr(sflg, '.') && !ft_strchr(sflg, '-') && flags.is0)
	{
		while (sflg[cnt] && (!ft_isdigit(sflg[cnt]) || sflg[cnt] == '0'))
			cnt++;
		flags.nbr2 = ft_atoi(&sflg[cnt]);
		flags.nbr1 = 0;
	}
	else
		flags = ft_get_prec_di2(flags, sflg, cnt);
	flags.prec = ft_strchr(sflg, '+') ? 1 : 0;
	flags.sgn = ft_strchr(sflg, '-') ? 1 : 0;
	flags.is0 = flags.sgn ? 0 : flags.is0;
	free(sflg);
	flags.isprec = 1;
	return (flags);
}

t_flags		ft_get_prec_di2(t_flags flags, char *sflg, int cnt)
{
	if (ft_strchr(sflg, '.') && sflg[0] != '.')
	{
		while (sflg[cnt] && ((!ft_isdigit(sflg[cnt]) && sflg[cnt] != '.') ||
					sflg[cnt] == '-' || sflg[cnt] == '+' || sflg[cnt] == '0'))
			cnt++;
		flags.nbr1 = ft_atoi(&sflg[cnt]);
		while (sflg[cnt] && sflg[cnt] != '.')
			cnt++;
		flags.nbr2 = ft_atoi(&sflg[cnt + 1]);
	}
	else if (ft_strchr(sflg, '.') && sflg[0] == '.')
		flags.nbr2 = ft_atoi(&sflg[cnt + 1]);
	else
	{
		while (sflg[cnt] && (sflg[cnt] == '-' || sflg[cnt] == '+' ||
					sflg[cnt] == '0'))
			cnt++;
		flags.nbr1 = ft_atoi(&sflg[cnt]);
		flags.isnb2 = 1;
	}
	return (flags);
}

t_flags		ft_reset_precision(t_flags flags)
{
	flags.nbr1 = 0;
	flags.nbr2 = 0;
	flags.sgn = 0;
	flags.spc = 0;
	flags.is0 = 0;
	flags.isprec = 0;
	flags.prec = 0;
	flags.isnb2 = 0;
	flags.hash = 0;
	return (flags);
}
