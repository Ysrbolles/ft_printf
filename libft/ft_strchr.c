/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 10:24:24 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/01 10:34:51 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	chr;
	char	*ptr;

	chr = 0;
	ptr = 0;
	while (((char *)s)[chr] != (char)c && ((char *)s)[chr] != '\0')
		chr++;
	if (((char *)s)[chr] == (char)c)
		ptr = &((char *)s)[chr];
	return (ptr);
}
