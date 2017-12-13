/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:24:23 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/13 16:44:24 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void print_list(t_fd_list **list) {
	t_fd_list *kr = *list;
	while (kr)
	{
		printf("[fd : %d] [str : \'%s\']\n", kr->fd, kr->str);
		kr = kr->next;
	}
}

void 		delete_curr(t_fd_list **list, t_fd_list *curr)
{
	t_fd_list *kr = *list;

	print_list(list);
	while (kr->next)
	{
		///printf("lol\n");
	//	print_list(list);
		///printf("test2\n");
		if (kr->next->fd == curr->fd)
		{
			if (curr->next)
				kr->next = curr->next;
			free(curr->str);
			free(curr);
			return ;
		}
		kr = kr->next;
	}
	free(curr->str);
	free(curr);
}

t_fd_list	*get_line_by_fd(t_fd_list **list, int fd)
{
	t_fd_list	*new;
	t_fd_list	*kr = *list;
	while (kr->next)
	{
	//	print_list(list);
		 ///printf("test1\n");
		if (kr->fd == fd)
			return (kr);
		// printf("test2\n");
		/*if (!(kr->next))
			break;*/
		// printf("test3\n");
		kr = kr->next;
		// printf("test4\n");
	}
	///printf("%d\n", kr->fd);
	if (!(new = (t_fd_list*)malloc(sizeof(t_fd_list))))
		return (NULL);
		// printf("tes4\n");
	new->fd = fd;
	new->str = ft_strnew(0);
	new->next = NULL;
	if (kr)
		kr->next = new;
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
	///print_list(&list);
	if (!list)
	{
		if (!(list = (t_fd_list*)malloc(sizeof(t_fd_list))))
			return (-1);
		list->fd = -42;
	}
	///printf("%d %s\n", list->fd, list->str);
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
		/*if (i == 0)
			*line = ft_strdup("");
		else*/
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
	if (curr != NULL)
		delete_curr(&list, curr);
	///printf("LISTEFINALE DE LA MORT\n");
	///print_list(&list);
	return (0);
}

int		main(int argc, char **argv)
{
	(void)argc;
	char *str;
	char *str2;
	//int		i = 0;
	int fd = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_RDONLY);
	/*get_next_line(fd, &str);
	printf("GNL fd1 : %s\n", str);*/
	get_next_line(fd2, &str2);
	printf("GNL fd2 : %s\n", str2);
	get_next_line(fd, &str);
	printf("GNL fd1 : %s\n", str);
	get_next_line(fd2, &str2);
	printf("GNL fd2 : %s\n", str2);
	get_next_line(fd, &str);
	printf("GNL fd1 : %s\n", str);
	get_next_line(fd2, &str2);
	printf("GNL fd2 : %s\n", str2);
	get_next_line(fd, &str);
	printf("GNL fd1 : %s\n", str);
	get_next_line(fd2, &str2);
	printf("GNL fd2 : %s\n", str2);
	get_next_line(fd, &str);
	printf("GNL fd1 : %s\n", str);
	/*while (get_next_line(fd, &str) || get_next_line(fd2, &str2))
	{
		printf("fd1 %d : \'%s\'\n", ++i, str);
		printf("fd2 %d : \'%s\'\n", i, str2);
	}*/
	return (0);
}
