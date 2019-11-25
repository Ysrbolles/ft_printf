/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:55:54 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/02 20:24:25 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t chr;
	size_t ndl;

	chr = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[chr] != '\0' && len > 0)
	{
		ndl = 0;
		while (needle[ndl] != '\0' && len - ndl > 0)
		{
			if (needle[ndl] != haystack[chr + ndl])
				break ;
			ndl++;
		}
		if (needle[ndl] == '\0')
			return (&((char *)haystack)[chr]);
		chr++;
		len--;
	}
	return (NULL);
}
