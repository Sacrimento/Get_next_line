/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:36:07 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/14 17:03:49 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	int		i;

	i = 0;
	if (!(s && f))
		return ;
	while (s[i])
	{
		f(&(s[i]));
		i++;
	}
}