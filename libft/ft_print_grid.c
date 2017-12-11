/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:49:11 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/16 16:50:16 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_grid(char **tab)
{
	int cursor;

	cursor = 0;
	while (tab[cursor] != 0)
	{
		ft_putstr(tab[cursor]);
		ft_putchar('\n');
		cursor++;
	}
}
