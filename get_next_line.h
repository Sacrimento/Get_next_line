/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:22:29 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/16 12:09:14 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/includes/libft.h"
# define BUFF_SIZE 2048

typedef struct	s_fd_list
{
	int					fd;
	char				*str;
	struct s_fd_list	*next;
}				t_fd_list;

int				get_next_line(const int fd, char **line);

#endif
