/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:11:52 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/14 17:56:58 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new_s;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(new_s = (char*)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
		new_s[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_s[j++] = s2[i++];
	free((char*)s1);
	new_s[j] = '\0';
	return (new_s);
}
