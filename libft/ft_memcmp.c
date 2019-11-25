/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:49:16 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/01 21:47:46 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			chk;
	const U_CHAR	*str1;
	const U_CHAR	*str2;

	chk = 0;
	str1 = (const U_CHAR *)s1;
	str2 = (const U_CHAR *)s2;
	while (chk < n)
	{
		if (str1[chk] != str2[chk])
			return (str1[chk] - str2[chk]);
		chk++;
	}
	return (0);
}
