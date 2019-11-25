/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:39:25 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/07 15:34:44 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	nch;
	U_CHAR	*str;

	nch = 0;
	str = (U_CHAR *)b;
	while (nch < len)
		str[nch++] = (U_CHAR)c;
	return ((void *)str);
}
