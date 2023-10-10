/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:40:58 by fde-sist          #+#    #+#             */
/*   Updated: 2023/09/24 21:40:08 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	last_row(int n, int j, char tab[6]);
void	top_row(int n, int j, char tab[6]);

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\0", 1);
}

void	new_line_increment_i(int *i)
{
	*i = *i + 1;
	ft_putchar('\n');
}

void	generate_top_or_bottom(int i, int n, int j, char tab[6])
{
	if (i == 0)
		top_row(n, j, tab);
	else
		last_row(n, j, tab);
}
