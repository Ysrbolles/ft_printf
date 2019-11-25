/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:04:23 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/11 20:28:19 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	chk;
	int		sum;
	int		ng;

	chk = 0;
	sum = 0;
	ng = 1;
	while ((str[chk] >= 9 && str[chk] <= 13) || str[chk] == 32)
		chk++;
	while ((str[chk] >= 48 && str[chk] <= 57) || ((str[chk] == 43 ||
					str[chk] == 45) && (!((str[chk - 1] >= 48 &&
								str[chk - 1] <= 57) || (str[chk - 1] == 43
									|| str[chk - 1] == 45)))))
	{
		if (str[chk] == 45)
			ng = -1;
		if (str[chk] >= 48 && str[chk] <= 57)
			sum = sum * 10 + (str[chk] - 48);
		chk++;
	}
	return (sum * ng);
}
