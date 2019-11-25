/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 22:29:16 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/04 11:35:32 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	frst;
	size_t	len;
	char	*fresh;

	len = 0;
	frst = 0;
	fresh = NULL;
	if (s)
	{
		while (s[frst] == 32 || s[frst] == 10 || s[frst] == 9)
			frst++;
		len = ft_strlen(&s[frst]);
		while (s[frst] != 0 && (s[len + frst - 1] == 32 ||
					s[len + frst - 1] == 10 || s[len + frst - 1] == 9))
			len--;
		if (!(fresh = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		fresh = ft_strncpy(fresh, &s[frst], len);
		fresh[len] = '\0';
		return (fresh);
	}
	return (NULL);
}
