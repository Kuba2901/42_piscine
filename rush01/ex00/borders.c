/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:51:41 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/03 13:14:04 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	get_border_len(char *str)
{
	int	i;
	int	numbers_count;

	i = 0;
	numbers_count = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			numbers_count++;
		else if (str[i] != ' ')
			return (-1);
		i++;
	}
	return (numbers_count);
}

int	*load_nums(char *str)
{
	int	num_count;
	int	*nums;
	int	i;
	int	num_index;

	num_count = get_border_len(str);
	nums = (int *)malloc(num_count * 4);
	i = 0;
	num_index = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			nums[num_index++] = str[i] - '0';
		i++;
	}
	return (nums);
}

void	init_fill_values(int *i, int *bord_num, int *k)
{
	*i = 0;
	*bord_num = 0;
	*k = 0;
}

void	fill_borders(char *str, int border_len, int **tab)
{
	int	i;
	int	bord_num;
	int	k;
	int	*nums;
	
	init_fill_values(&i, &bord_num, &k);
	nums = load_nums(str);
	while (i < get_border_len(str))
	{
		if (bord_num == 0)
			tab[0][++k] = nums[i];
		else if (bord_num == 1)
			tab[border_len - 1][++k] = nums[i];
		else if (bord_num == 2)
			tab[++k][0] = nums[i];
		else
			tab[++k][border_len - 1] = nums[i];
		if ((i + 1) % (border_len - 2) == 0)
		{
			bord_num++;
			k = 0;
		}
		i++;
	}
}
