/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:21:12 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/02 21:05:30 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	init_tab(int tab[10][10])
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		while (j < 10)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	queen_safe(int x, int y, int tab[10][10])
{
	int	i;
	int	j;

	// 1. Left horizontal
	j = x;
	while (j >= 0)
	{
		if (tab[y][j] != 0)
			return (-1);
		j--;
	}

	// 2. Left top
	i = y;
	j = x;
	while (i >= 0 && j >= 0)
	{
		if (tab[i][j] != 0)
			return (-1);
		i--;
		j--;
	}

	// 3. Left bottom
	i = y;
	j = x;
	while (i < 10 && j >= 0)
	{
		if (tab[i][j] != 0)
			return (-1);
		j--;
		i++;
	}
	return (1);
}

/**
 * go through each row (begin from different spots)
 * if it's safe to place the queen, place and move on to the next column (call with ++x)
 * if it's not safe to place try another position in the column
 **/

void	print_tab(int tab[10][10])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		while (j < 10)
		{
			printf("%d ", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
}

int	count_combinations(int x, int tab[10][10])
{
	
}

int	ft_ten_queens_puzzle(void)
{
	int	tab[10][10];
	int	combinations;
	int	i;
	int	x;

	init_tab(tab);
	combinations = 0;
	i = 0;
	while (i < 10)
	{
		combinations += count_combinations(
		i++;
	}

	printf("found: %d combinations\n", combinations);
	return (combinations);
}

int	main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}
