/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:42:41 by alzaynou          #+#    #+#             */
/*   Updated: 2019/11/23 17:27:45 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_to_octal(unsigned int num)
{
	unsigned int	num1;
	int				cnt;
	char			*str;

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
		str[cnt] = (num % 8) + '0';
		num /= 8;
		cnt--;
	}
	return (str);
}

char	*ft_to_hexa(unsigned int num, char c)
{
	unsigned int	num1;
	int				cnt;
	char			*str;

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

char	*ft_unsigned(unsigned int num)
{
	int				cnt;
	unsigned int	num1;
	char			*str;

	cnt = 1;
	num1 = num;
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

char	*ft_ptr(char c, unsigned long long int num)
{
	unsigned long long int	num1;
	int						cnt;
	char					*str;

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
		if ((num % 16) >= 10 && (c == 'x' || c == 'p'))
			str[cnt--] = ((num % 16) % 10) + 'a';
		else if ((num % 16) >= 10 && c == 'X')
			str[cnt--] = ((num % 16) % 10) + 'A';
		else
			str[cnt--] = (num % 16) + '0';
		num /= 16;
	}
	return (str);
}

char	*ft_long_long_octa(unsigned long long int num)
{
	unsigned long long int	num1;
	int						cnt;
	char					*str;

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
		str[cnt] = (num % 8) + '0';
		num /= 8;
		cnt--;
	}
	return (str);
}
