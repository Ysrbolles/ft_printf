/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 22:07:02 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/03 22:24:40 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	len;

	fresh = NULL;
	len = 0;
	if (s1 != NULL && s2 != NULL)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(fresh = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		fresh = ft_strcpy(fresh, s1);
		fresh = ft_strcat(fresh, s2);
		return (fresh);
	}
	return (NULL);
}
