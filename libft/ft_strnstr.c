/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:10:49 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/14 20:33:03 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!nee[i])
		return ((char*)&(hay[0]));
	while (hay[i] && i < len)
	{
		j = 0;
		while (hay[i + j] == nee[j] && (i + j) < len)
		{
			j++;
			if (!nee[j])
				return ((char*)(&hay[i]));
		}
		i++;
	}
	return (NULL);
}
