/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:16:49 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/04 19:00:13 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cnt(int n)
{
	long	nb;
	size_t	cnt;

	nb = n;
	cnt = 0;
	if (nb <= 0)
	{
		nb *= -1;
		cnt = 1;
	}
	while (nb > 0)
	{
		nb /= 10;
		cnt++;
	}
	return (cnt);
}

char			*ft_itoa(int n)
{
	char	*fresh;
	long	nbr;
	size_t	cnt;

	fresh = NULL;
	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	cnt = ft_cnt(n);
	if (!(fresh = (char *)malloc(sizeof(char) * cnt + 1)))
		return (NULL);
	fresh[cnt] = '\0';
	cnt--;
	while (nbr > 0)
	{
		fresh[cnt] = (nbr % 10) + 48;
		nbr /= 10;
		cnt--;
	}
	if (n < 0)
		fresh[0] = '-';
	if (n == 0)
		fresh[0] = '0';
	return (fresh);
}
