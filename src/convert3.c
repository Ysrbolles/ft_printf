/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:06:01 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/23 17:28:49 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_convert_short_di(short int num)
{
	unsigned short int	num1;
	char				*str;
	int					cnt;

	num1 = num < 0 ? num * -1 : num;
	cnt = num <= 0 ? 1 : 0;
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
		str[cnt] = (num1 % 10) + '0';
		num1 /= 10;
		cnt--;
	}
	if (num < 0)
		str[0] = '-';
	return (str);
}

char	*ft_convert_ushort_xx(char c, unsigned short int num)
{
	unsigned short int	num1;
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

char	*ft_convert_ushort_o(unsigned short int num)
{
	unsigned short int	num1;
	char				*str;
	int					cnt;

	num1 = num;
	cnt = 1;
	while (num1 > 7)
	{
		num1 /= 8;
		cnt++;
	}
	SAFE(str = (char *)malloc(sizeof(char) * (cnt + 1)));
	str[cnt--] = '\0';
	while (cnt >= 0)
	{
		str[cnt--] = (num % 8) + '0';
		num /= 8;
	}
	return (str);
}

char	*ft_convert_ushort_u(unsigned short int num)
{
	unsigned short int	num1;
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
		str[cnt--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

char	*ft_convert_uchar_u(unsigned char num)
{
	unsigned char	num1;
	char			*str;
	int				cnt;

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
		str[cnt--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
