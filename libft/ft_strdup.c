/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:07:05 by alzaynou          #+#    #+#             */
/*   Updated: 2019/03/31 16:25:11 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	cnt;
	char	*str;

	cnt = 0;
	str = NULL;
	while (s1[cnt])
		cnt++;
	str = malloc(sizeof(char) * cnt + 1);
	if (str != NULL)
	{
		cnt = 0;
		while (s1[cnt] != '\0')
		{
			str[cnt] = s1[cnt];
			cnt++;
		}
		str[cnt] = '\0';
	}
	return (str);
}
