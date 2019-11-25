/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 18:30:39 by alzaynou          #+#    #+#             */
/*   Updated: 2019/03/31 19:13:34 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t cnt;

	cnt = 0;
	while (((char *)src)[cnt] != '\0')
	{
		dst[cnt] = ((char *)src)[cnt];
		cnt++;
	}
	dst[cnt] = '\0';
	return (dst);
}
