/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:44:42 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/15 10:14:05 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int		mini(size_t size, size_t dlen)
{
	int		ret;

	if (size > dlen)
		ret = dlen;
	else
		ret = size;
	return (ret);
}

static size_t	ft_len(const char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	int		j;
	int		i;
	size_t	dlen;
	size_t	z;

	i = 0;
	j = 0;
	z = 0;
	dlen = ft_len(dst);
	if (size == 0)
		return (ft_len(src));
	while (dst[i])
	{
		i++;
		z++;
	}
	while (src[j] && z < size - 1)
	{
		dst[i + j] = src[j];
		j++;
		z++;
	}
	dst[i + j] = '\0';
	return (ft_len(src) + mini(size, dlen));
}
