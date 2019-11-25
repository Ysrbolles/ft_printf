/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:00:22 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/07 10:55:46 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;

	if (!(fresh = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	fresh->content = (void *)malloc(sizeof(void) * content_size);
	if (!content)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
	}
	else
	{
		fresh->content = ft_strcpy(((char *)(fresh)->content),
				((const char *)(content)));
		fresh->content_size = content_size;
	}
	fresh->next = NULL;
	return (fresh);
}
