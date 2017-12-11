/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:33:22 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/17 10:04:07 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	void	*new_area;
	size_t	i;

	i = 0;
	if (!(new_area = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	if (new_area == NULL)
		return (NULL);
	while (i < size)
	{
		((char*)new_area)[i] = 0;
		i++;
	}
	return (new_area);
}
