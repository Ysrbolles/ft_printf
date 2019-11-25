/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 10:48:36 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/01 10:51:16 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	chr;
	char	*ptr;

	chr = 0;
	ptr = 0;
	while (((char *)s)[chr] != '\0')
		chr++;
	while (((char *)s)[chr] != (char)c && chr > 0)
		chr--;
	if (((char *)s)[chr] == (char)c)
		ptr = &((char *)s)[chr];
	return (ptr);
}
