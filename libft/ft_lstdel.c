/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:31:02 by alzaynou          #+#    #+#             */
/*   Updated: 2019/04/07 18:18:33 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (!(*alst == NULL))
		while (*alst)
		{
			del((*alst)->content, (*alst)->content_size);
			temp = *alst;
			*alst = (*alst)->next;
			free(temp);
		}
	alst = NULL;
}
