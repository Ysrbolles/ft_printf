/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:49:25 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/08 11:40:11 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t cpy;

	cpy = 0;
	while (cpy < n)
	{
		((char *)dst)[cpy] = ((char *)src)[cpy];
		cpy++;
	}
	return ((char *)dst);
}
