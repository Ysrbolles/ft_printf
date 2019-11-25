/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 00:09:39 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/08 22:43:45 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *buf[len];

	if (len <= 65535)
	{
		ft_memcpy(buf, src, len);
		ft_memcpy(dst, buf, len);
	}
	return (dst);
}
