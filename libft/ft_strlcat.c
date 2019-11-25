/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 21:55:48 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/02 17:18:16 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t cnt1;
	size_t cnt2;
	size_t lght;

	cnt1 = 0;
	cnt2 = 0;
	lght = ft_strlen(dst);
	while (size > 0 && lght < size - 1 && ((char *)src)[cnt1] != '\0')
		dst[lght++] = ((char *)src)[cnt1++];
	dst[lght] = '\0';
	while (((char *)src)[cnt1 + cnt2] != '\0')
		cnt2++;
	if (cnt2 == 0 && lght < size)
		return (lght);
	if (lght < size)
		cnt2--;
	return (cnt2 + size);
}
