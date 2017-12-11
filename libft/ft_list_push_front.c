/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:28:58 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/15 11:02:10 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_list_push_front(void *data, t_list *list)
{
	t_list	*elem;

	if (!(elem = ft_lstnew(data, sizeof(data) + ft_strlen((char*)data))))
		return (NULL);
	elem->next = list;
	return (elem);
}
