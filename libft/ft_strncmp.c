/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:36:08 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/02 17:35:34 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t chk;

	chk = 0;
	while (s1[chk] == s2[chk] &&
			s1[chk] != 0 && s2[chk] != 0 && chk < n - 1)
		chk++;
	if (n > 0)
		return (((U_CHAR *)s1)[chk] - ((U_CHAR *)s2)[chk]);
	return (0);
}
