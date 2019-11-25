/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:59:34 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/23 23:12:31 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_convert_long_di(long int num)
{
	unsigned long int	num1;
	char				*str;
	int					cnt;

	cnt = num <= 0 ? 1 : 0;
	num1 = num < 0 ? num * -1 : num;
	while (num1 > 0)
	{
		num1 /= 10;
		cnt++;
	}
	SAFE(str = (char *)malloc(sizeof(char) * (cnt + 1)));
	str[cnt--] = '\0';
	num1 = num < 0 ? num * -1 : num;
	while (cnt >= 0)
	{
		str[cnt--] = (num1 % 10) + '0';
		num1 /= 10;
	}
	if (num < 0)
		str[0] = '-';
	return (str);
}

char	*ft_convert_ulong_xx(char c, unsigned long int num)
{
	unsigned long int	num1;
	char				*str;
	int					cnt;

	num1 = num;
	cnt = 1;
	while (num1 > 15)
	{
		num1 /= 16;
		cnt++;
	}
	SAFE(str = (char *)malloc(sizeof(char) * (cnt + 1)));
	str[cnt--] = '\0';
	while (cnt >= 0)
	{
		if ((num % 16) >= 10 && c == 'x')
			str[cnt--] = ((num % 16) % 10) + 'a';
		else if ((num % 16) >= 10 && c == 'X')
			str[cnt--] = ((num % 16) % 10) + 'A';
		else
			str[cnt--] = (num % 16) + '0';
		num /= 16;
	}
	return (str);
}

char	*ft_cnvert_ulong_o(unsigned long int num)
{
	unsigned long int	num1;
	char				*str;
	int					cnt;

	cnt = 1;
	num1 = num;
	while (num1 > 7)
	{
		num1 /= 8;
		cnt++;
	}
	SAFE(str = (char *)malloc(sizeof(char) * (cnt + 1)));
	str[cnt--] = '\0';
	while (cnt >= 0)
	{
		str[cnt] = (num % 8) + '0';
		num /= 8;
		cnt--;
	}
	return (str);
}

char	*ft_convert_ulong_u(unsigned long int num)
{
	unsigned long int	num1;
	char				*str;
	int					cnt;

	num1 = num;
	cnt = 1;
	while (num1 > 9)
	{
		num1 /= 10;
		cnt++;
	}
	SAFE(str = (char *)malloc(sizeof(char) * (cnt + 1)));
	str[cnt--] = '\0';
	while (cnt >= 0)
	{
		str[cnt] = (num % 10) + '0';
		num /= 10;
		cnt--;
	}
	return (str);
}
