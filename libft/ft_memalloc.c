/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:10:14 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/08 13:27:01 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = 0;
	if (size >= 1)
		if (!(ptr = (void *)malloc(sizeof(void) * size)))
			return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}
