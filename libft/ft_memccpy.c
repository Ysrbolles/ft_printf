/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:30:42 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/07 19:04:57 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	U_CHAR	*msrc;
	U_CHAR	*mdst;
	size_t	nb;

	msrc = (U_CHAR *)src;
	mdst = (U_CHAR *)dst;
	nb = 0;
	while (nb < n)
	{
		mdst[nb] = msrc[nb];
		if (msrc[nb] == (U_CHAR)c)
			return (&mdst[nb + 1]);
		nb++;
	}
	return (NULL);
}
