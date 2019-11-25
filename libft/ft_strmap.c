/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:41:40 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/03 13:09:23 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	size;
	char	*fresh;

	fresh = NULL;
	if (s != NULL)
	{
		size = ft_strlen(s);
		fresh = (char *)malloc(sizeof(char) * size + 1);
		if (!fresh)
			return (NULL);
		size = 0;
		while (s[size] != '\0')
		{
			fresh[size] = (*f)(((char *)s)[size]);
			size++;
		}
		fresh[size] = '\0';
	}
	return (fresh);
}
