/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:13:04 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/09 17:02:35 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

static	int	is_here(char *s, char c)
{
	int		i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	int			ret;
	int			i;
	char		buff[BUFF_SIZE + 1];

	i = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!str)
	{
		if (!(str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
	}
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (!*buff)
			return (-1);
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
		if (is_here(str, '\n'))
			break;
	}
	if (ret < 0)
		return(-1);
	if (str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		str[i] = '\0';
		*line = ft_strsub(str, 0, i);
		str = &(str[i + 1]);
		printf("%s\n", *line);
		return (1);
	}
	//free(str);
	*line = str;
	return (0);
}
