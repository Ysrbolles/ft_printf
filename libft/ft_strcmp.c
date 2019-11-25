/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:22:53 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/01 17:29:29 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t chk;

	chk = 0;
	while (((U_CHAR *)s1)[chk] == ((U_CHAR *)s2)[chk]
			&& ((U_CHAR *)s1)[chk] != '\0' && ((U_CHAR *)s2)[chk] != '\0')
		chk++;
	return (((U_CHAR *)s1)[chk] - ((U_CHAR *)s2)[chk]);
}
