#include "get_next_line.h"
#include <stdio.h>
int		main(int argc, char **argv)
{
	(void)argc;
	char	*str;
	int		fd = open(argv[1], O_RDONLY);
	int		fd2 = open(argv[2], O_RDONLY);
	int		fd3 = open(argv[3], O_RDONLY);

	get_next_line(fd, &str);
	printf("%s\n", str);
	ft_memdel((void**)&str);
	get_next_line(fd2, &str);
	printf("%s\n", str);
	ft_memdel((void**)&str);
	while (get_next_line(fd3, &str) == 1)
	{
		printf("%s\n", str);
		ft_memdel((void**)&str);
	}
	get_next_line(fd, &str);
	printf("%s\n", str);
	ft_memdel((void**)&str);
	get_next_line(fd2, &str);
	printf("%s\n", str);
	ft_memdel((void**)&str);
	get_next_line(fd2, &str);
	printf("%s\n", str);
	ft_memdel((void**)&str);
	get_next_line(fd2, &str);
	printf("%s\n", str);
	ft_memdel((void**)&str);
	get_next_line(fd, &str);
	printf("%s\n", str);
	ft_memdel((void**)&str);
	get_next_line(fd, &str);
	printf("%s\n", str);
	ft_memdel((void**)&str);
	return (0);
}
