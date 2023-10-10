/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:51:36 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/03 13:48:17 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	print_tab(int border, int border_len, int **tab);
void	init_tab(int border_len, int **tab);
void	putstr(char *str);
int		get_border_len(char *str);
void	fill_borders(char *str, int border_len, int **tab);
int		count_sum_goal(int border_len);
void	fill_highest_lowest(int border_len, int **tab);
int		check_correct(int border_len, int **tab);
int		find_combination(int border_len, int **tab);

int	main(int argc, char **argv)
{
	int	**tab;
	int	border_len;
	int	found;

	if (argc == 1 || get_border_len(argv[1]) == -1)
	{
		putstr("Error\n");
		return (0);
	}
	border_len = get_border_len(argv[1]) / 4 + 2;
	tab = (int **)malloc(border_len * 8);
	init_tab(border_len, tab);
	fill_borders(argv[1], border_len, tab);
	fill_highest_lowest(border_len, tab);
	found = find_combination(border_len, tab);
	if (found != 1)
	{
		putstr("Error\n");
		return (0);
	}
	print_tab(1, border_len, tab);
	free(tab);
	return (0);
}
