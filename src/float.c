/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:44:55 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/23 17:29:43 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_free_tab(char **tab)
{
	free(tab[1]);
	tab[1] = NULL;
	free(tab[0]);
	tab[0] = NULL;
	free(tab);
	tab = NULL;
}

char		*add_minus(char *str)
{
	char *ptr;

	ptr = str;
	str = ft_strjoin("-", str);
	free(ptr);
	return (str);
}

char		**ft_convert_double(double num)
{
	char		**tab;
	long long	nbr;
	int			cnt;

	cnt = 0;
	SAFE(tab = (char **)malloc(sizeof(char *) * 2));
	tab[0] = ft_long_long_di((long long int)(num));
	if (num < 0 && tab[0][0] != '-')
		tab[0] = add_minus(tab[0]);
	num = num < 0 ? -num : num;
	nbr = (long long)(num);
	num -= nbr;
	SAFE(tab[1] = (char *)malloc(sizeof(char) * 21));
	while (cnt < 20)
	{
		num *= 10.0;
		nbr = (long long)(num);
		tab[1][cnt++] = nbr + '0';
		num -= nbr;
	}
	tab[1][cnt] = '\0';
	return (tab);
}
