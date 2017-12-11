/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:07:14 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/28 13:08:19 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	unsigned int	size;

	size = (unsigned int)ft_list_size(begin_list);
	i = 0;
	if (size < nbr)
		return (NULL);
	while (i < nbr)
	{
		if (begin_list == NULL)
			return (NULL);
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}
