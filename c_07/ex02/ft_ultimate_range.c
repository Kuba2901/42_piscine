/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:57:17 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/09 19:31:19 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	diff;
	int	*nums;
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	diff = max - min;
	nums = (int *)malloc(diff * 4);
	if (!nums)
		return (-1);
	i = 0;
	while (min < max)
		nums[i++] = min++;
	*range = nums;
	return (i);
}
