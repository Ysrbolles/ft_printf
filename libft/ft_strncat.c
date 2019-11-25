/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 21:13:15 by alzaynou          #+#    #+#             */
/*   Updated: 2019/03/31 21:40:43 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t cnt1;
	size_t cnt2;

	cnt1 = 0;
	cnt2 = 0;
	while (s1[cnt1] != '\0')
		cnt1++;
	while (cnt2 < n && ((char *)s2)[cnt2] != '\0')
	{
		s1[cnt1] = ((char *)s2)[cnt2];
		cnt1++;
		cnt2++;
	}
	s1[cnt1] = '\0';
	return (s1);
}
