/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:44:20 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/14 16:29:32 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char*)s)[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (NULL);
	return ((void*)&(((unsigned char *)s)[i]));
}
