/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_correct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:13:08 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/03 13:48:18 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	count_sum_goal(int border_len);

void	clear_variables(int	*desired, int *highest, int *found, int *sum)
{
	*desired = 0;
	*highest = 0;
	*found = 0;
	*sum = 0;
}

int	check_correct(int border_len, int **tab)
{
	int	i;
	int	j;
	int	highest;
	int	desired;
	int	found;
	int	sum;
	int	num;
	int	sum_goal;

	desired = 0;
	highest = 0;
	sum = 0;
	i = 1;
	j = 0;
	num = 0;
	found = 0;
	sum_goal = count_sum_goal(border_len);
	// 1. sideways: left -> right
	while (i < border_len - 1)
	{
		while (j < border_len - 1)
		{	
			num = tab[i][j];
			if (num == 0)
				return (-1);
			else if (j == 0)
				desired = num;
			else if (num > highest)
			{
				highest = num;
				found++;
			}
			if (j != 0)
				sum += num;
			j++;
		}
		if (found < desired || sum != sum_goal)
		{
			return (-1);
		}
		found = 0;
		highest = 0;
		sum = 0;
		j = 0;
		i++;
	}
	// 2. sideways: left <- right
	i = 1;
	j = border_len - 1;
	while (i < border_len - 1)
	{
		while (j > 0)
		{	
			num = tab[i][j];
			if (j == border_len - 1)
				desired = num;
			else if (num > highest)
			{
				highest = num;
				found++;
			}
			if (j != border_len - 1)
				sum += num;
			j--;
		}
		if (found < desired || sum != sum_goal)
		{
			return (-1);
		}
		found = 0;
		highest = 0;
		sum = 0;
		j = border_len - 1;
		i++;
	}
	// 3. up -> down
	i = 1;
	j = 0;
	while (i < border_len - 1)
	{
		while (j < border_len - 1)
		{
			num = tab[j][i];
			if (j == 0)
				desired = num;
			else if (num > highest)
			{
				highest = num;
				found++;
			}
			if (j != 0)
				sum += num;
			j++;
		}
		if (found < desired || sum != sum_goal)
			return (-1);
		found = 0;
		sum = 0;
		highest = 0;
		j = 0;
		i++;
	}
	// 4. down -> up
	i = 1;
	j = border_len - 1;
	while (i < border_len - 1)
	{
		while (j > 0)
		{	
			num = tab[j][i];
			if (j == border_len - 1)
				desired = num;
			else if (num > highest)
			{
				highest = num;
				found++;
			}
			if (j != border_len - 1)
				sum += num;
			j--;
		}
		if (found < desired || sum != sum_goal)
			return (-1);
		found = 0;
		sum = 0;
		highest = 0;
		j = border_len - 1;
		i++;
	}
	return (1);
}
