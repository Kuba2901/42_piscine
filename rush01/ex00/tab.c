/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:48:02 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/03 13:17:05 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_tab(int no_border, int border_len, int **tab)
{
	int		y;
	int		x;
	char	a;

	y = 0 + no_border;
	x = 0 + no_border;
	while (y < border_len - no_border)
	{
		while (x < border_len - no_border)
		{
			a = tab[y][x] + 48;
			write(1, &a, 1);
			if (x != border_len - no_border - 1)
				write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		x = 0 + no_border;
		y++;
	}
	write(1, "\n\n", 2);
}

void	init_tab(int border_len, int **tab)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < border_len)
	{
		tab[y] = (int *)malloc(border_len * 8);
		while (x < border_len)
		{
			if (y == 0 || y == border_len - 1)
			{
				if (x == 0 || x == border_len - 1)
					tab[y][x] = 40;
			}
			else
				tab[y][x] = 0;
			x++;
		}
		x = 0;
		y++;
	}
}
