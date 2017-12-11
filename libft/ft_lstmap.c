/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:25:26 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/14 18:08:16 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *list, t_list *(f)(t_list *elem))
{
	t_list	*tmp;
	t_list	**alst;

	if (!(alst = (t_list**)malloc(sizeof(t_list*))))
		return (NULL);
	if (!list)
		return (NULL);
	if (!(*alst = f(list)))
		return (NULL);
	tmp = *alst;
	while (list->next)
	{
		if (!(tmp->next = f(list->next)))
			return (NULL);
		tmp = tmp->next;
		list = list->next;
	}
	return (*alst);
}
