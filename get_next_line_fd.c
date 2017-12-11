#include "get_next_line.h"

#include <stdio.h>

void        ft_list_del_fd(t_fd_list *list, int fd)
{
  t_fd_list *before;
  t_fd_list *destroy;

  list = list->next;
  while (list)
  {
    if (list->fd == fd)
    {
      destroy = list;
      list = list->next;
      before->next = list;
      free(destroy->str);
      free(destroy);
      return;
    }
    list = list->next;
    before = before->next;
  }
}

t_fd_list	*add_fd(int fd, t_fd_list *begin)
{
	t_fd_list *list;
	t_fd_list *new;

	list = begin;
	while (list->next)
		list = list->next;
	if (!((new = (t_fd_list*)malloc(sizeof(t_fd_list)))))
		return (NULL);
	new->fd = fd;
	new->str = NULL;
	if (list)
		list->next = new;
	else
		return (new);
	return (begin);
}

t_fd_list   *get_line_fd(t_fd_list *list, int fd)
{
  t_fd_list *before;

  if (list)
  	before = list;
  while (list)
  {
    list = list->next;
    if (list->fd == fd)
      return (list);
    before = before->next;
  }
  return (NULL);
}

static	int	is_here(char *s, char c, t_fd_list *list, int fd)
{
	int		i = 0;
	(void)list;
	(void)fd;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
    	/*if (!s[i + 1])
    	{
			printf("lol\n");
      		ft_list_del_fd(list, fd);
      		return (1);
    	}*/
		i++;
	}
	return (0);
}

int		get_next_line_fd(int fd, char **line)
{
	int			ret;
	int			i;
	char		buff[BUFF_SIZE + 1];
 	static t_fd_list *begin;
	t_fd_list	*list;

	i = 0;
	if ((list = get_line_fd(begin, fd)))
		printf("REUSSI\n");
	else {
		begin = add_fd(fd, begin);
		get_next_line_fd(fd, line);
		return 1;
	}
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!list->str)
	{
		if (!(list->str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
	}
	while (!(is_here(list->str, '\n', list, fd)))
	{
		printf("BOUCLE1\n");
    	ret = read(fd, buff, BUFF_SIZE);
		if (!*buff)
			return (-1);
		buff[ret] = '\0';
		list->str = ft_strjoin(list->str, buff);
		printf("BOUCLE2\n");
	}
	if (list->str[i])
	{
		while (list->str[i] != '\n' && list->str[i])
			i++;
		*line = ft_strsub(list->str, 0, i);
		list->str = &(list->str[i + 1]);
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	(void)argc;
	char *str = NULL;
	int fd = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_RDONLY);
	get_next_line_fd(fd, &str);
	printf("%s\n", str);
	get_next_line_fd(fd2, &str);
	printf("%s\n", str);
	get_next_line_fd(fd, &str);
	printf("%s\n", str);
	return (0);
}
