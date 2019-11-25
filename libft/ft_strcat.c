/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 18:59:42 by alzaynou          #+#    #+#             */
/*   Updated: 2019/03/31 20:54:44 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t cnt1;
	size_t cnt2;

	cnt1 = 0;
	cnt2 = 0;
	while (s1[cnt1] != '\0')
		cnt1++;
	while (((char *)s2)[cnt2] != '\0')
	{
		s1[cnt1] = ((char *)s2)[cnt2];
		cnt2++;
		cnt1++;
	}
	if (((char *)s2)[cnt2] == '\0')
		s1[cnt1] = '\0';
	return (s1);
}
