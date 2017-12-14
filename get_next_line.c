/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:21:29 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/14 13:13:56 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd_list	*get_line_by_fd(t_fd_list **list, int fd)
{
	t_fd_list	*current;
	t_fd_list	*new;

	current = *list;
	if (current->fd == fd)
		return (current);
	while (current->next)
	{
		if (current->next->fd == fd)
			return (current->next);
		current = current->next;
	}
	if (!(new = (t_fd_list*)malloc(sizeof(t_fd_list))))
		return (NULL);
	new->fd = fd;
	new->str = ft_strnew(0);
	new->next = NULL;
	if (current)
		current->next = new;
	else
		*list = new;
	return (new);
}

int			get_next_line(const int fd, char **line)
{
	static t_fd_list	*list;
	t_fd_list			*current;
	int					ret;
	int					i;
	char				buff[BUFF_SIZE + 1];

	if (!list)
	{
		if (!(list = (t_fd_list*)malloc(sizeof(t_fd_list))))
			return (-1);
		list->fd = -1337;
		list->next = NULL;
	}
	if (!(current = get_line_by_fd(&list, fd)) || fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && *buff)
	{
		buff[ret] = '\0';
		current->str = ft_strjoin(current->str, buff);
		if (ft_memchr(current->str, '\n', BUFF_SIZE))
			break ;
	}
	if (ret < 0)
		return (-1);
	i = 0;
	if (*current->str)
	{
		while (current->str[i] != '\n' && current->str[i])
			i++;
		current->str[i] = '\0';
		*line = NULL;
		*line = ft_strsub(current->str, 0, i);
		current->str = &(current->str[i + 1]);
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	(void)argc;
	char	*str;
	int		fd = open(argv[1], O_RDONLY);
	int		fd2 = open(argv[2], O_RDONLY);

	get_next_line(fd, &str);
	printf("%s\n", str);
	get_next_line(fd2, &str);
	printf("%s\n", str);
	get_next_line(fd, &str);
	printf("%s\n", str);
	get_next_line(fd2, &str);
	printf("%s\n", str);
	return (0);
}
