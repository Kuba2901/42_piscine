/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:48:10 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/09 19:31:09 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	diff;
	int	*nums;
	int	i;

	if (min >= max)
		return (0);
	diff = max - min;
	nums = (int *)malloc(diff * 4);
	if (!nums)
		return (0);
	i = 0;
	while (min < max)
		nums[i++] = min++;
	return (nums);
}
