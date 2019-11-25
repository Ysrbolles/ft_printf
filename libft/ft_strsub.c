/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:03:57 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/03 22:05:25 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *fresh;

	fresh = NULL;
	if (s != NULL)
	{
		if (!(fresh = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		fresh = ft_strncpy(fresh, s + start, len);
		fresh[len] = '\0';
		return (fresh);
	}
	return (NULL);
}
