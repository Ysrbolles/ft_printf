/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:36:54 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/07 16:47:17 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	mkstr(char **tab, char const *s, char c)
{
	size_t cnt;
	size_t chk;
	size_t str;

	cnt = 0;
	chk = 0;
	str = 0;
	while (s[chk] != '\0')
	{
		if (s[chk] != c)
			cnt++;
		if (s[chk] != c && (s[chk + 1] == c || s[chk + 1] == 0))
		{
			tab[str] = (char *)malloc(sizeof(char) * cnt + 1);
			str++;
			cnt = 0;
		}
		chk++;
	}
}

static void	cpystr(char **tab, char const *s, char c)
{
	size_t cnt;
	size_t chk;
	size_t str;

	cnt = 0;
	chk = 0;
	str = 0;
	while (s[chk] != '\0')
	{
		if (s[chk] != c)
			tab[str][cnt++] = s[chk];
		if (s[chk] != c && (s[chk + 1] == c || s[chk + 1] == 0))
		{
			tab[str][cnt] = '\0';
			str++;
			cnt = 0;
		}
		chk++;
	}
	tab[str] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	cnt;
	size_t	chk;

	tab = NULL;
	cnt = 0;
	chk = 0;
	if (!s)
		return (NULL);
	while (s[chk] != '\0')
	{
		if (s[chk] != c && (s[chk + 1] == c || s[chk + 1] == 0))
			cnt++;
		chk++;
	}
	if (!(tab = (char **)malloc(sizeof(char *) * (cnt + 1))))
		return (NULL);
	mkstr(tab, s, c);
	cpystr(tab, s, c);
	return (tab);
}
