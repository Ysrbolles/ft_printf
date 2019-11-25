/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:46:22 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/07 11:17:32 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*temp;

	if (!lst)
		return (NULL);
	fresh = f(lst);
	lst = lst->next;
	temp = fresh;
	while (lst)
	{
		fresh->next = f(lst);
		lst = lst->next;
		fresh = fresh->next;
	}
	return (temp);
}
