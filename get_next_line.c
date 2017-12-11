/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:24:23 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/11 18:56:02 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void print_list(t_fd_list **list) {
	while (*list)
	{
		printf("[fd : %d] [str : \'%s\']\n", (*list)->fd, (*list)->str);
		*list = (*list)->next;
	}
}

void 		delete_curr(t_fd_list **list, t_fd_list *curr)
{
	while ((*list)->next)
	{
		if ((*list)->next == curr)
		{
			(*list)->next = curr->next;
			free(curr->str);
			free(curr);
			return ;
		}
		(*list) = (*list)->next;
	}
	if (!((*list)->next))
	{
		free((*list)->str);
		free(*list);
	}
}

t_fd_list	*get_line_by_fd(t_fd_list **list, int fd)
{
	t_fd_list	*new;

	while (*list)
	{
		if ((*list)->fd == fd)
			return (*list);
		if (!(*list)->next)
			break;
		*list = (*list)->next;
	}
	if (!(new = (t_fd_list*)malloc(sizeof(t_fd_list))))
		return (NULL);
	new->fd = fd;
	new->str = ft_strnew(0);
	new->next = NULL;
	if (*list)
		(*list)->next = new;
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	int					ret;
	static t_fd_list	*list;
	t_fd_list			*curr;
	char				buff[BUFF_SIZE + 1];
	int					i;
	char				*tmp;

	i = 0;
	//print_list(&list);
	if (!list)
	{
		if (!(list = (t_fd_list*)malloc(sizeof(t_fd_list))))
			return (-1);
		list->fd = -42;
	}
	//print_list(&list);
	if (!(curr = get_line_by_fd(&list, fd)) || fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && *buff)
	{
		//printf("LOL \n: %s\n", curr->str);
		buff[ret] = '\0';
		curr->str = ft_strjoin(curr->str, buff);
		if (ft_strchr(curr->str, '\n'))
			break;
	}
	if (ret < 0)
		return (-1);
	if (*curr->str)
	{
		while (curr->str[i] != '\n' && curr->str[i])
			i++;
		curr->str[i] = '\0';
		if (i == 0)
			*line = ft_strdup("");
		else
			*line = ft_strdup(curr->str);
		tmp = ft_strdup(&(curr->str[i + 1]));
		free(curr->str);
		curr->str = tmp;
		//free(tmp);
		//printf("line : %s\n", *line);
		//printf("curr->str : %s\n", curr->str);
		if (*line)
			return (1);
	}
	//print_list(&list);
	//delete_curr(&list, curr);
	//print_list(&list);
	return (0);
}

/*int		main(int argc, char **argv)
{
	(void)argc;
	char *str;
	char *str2;
	int fd = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_RDONLY);
	get_next_line(fd, &str);
	printf("GNL fd1 : %s\n", str);
	get_next_line(fd2, &str);
	printf("GNL fd2 : %s\n", str);
	get_next_line(fd, &str);
	printf("GNL fd1 : %s\n", str);
	while (get_next_line(fd, &str))
	{
		printf("%s\n", str);
		get_next_line(fd2, &str2);
		printf("%s\n", str2);
	}
	return (0);
}
*/