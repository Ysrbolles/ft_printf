/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:24:16 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/02 19:12:58 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t fnd;

	if (!n)
		return (NULL);
	fnd = 0;
	while (fnd < n)
	{
		if (((U_CHAR *)s)[fnd] != (U_CHAR)c)
			fnd++;
		else
			return (&((U_CHAR *)s)[fnd]);
	}
	return (NULL);
}
