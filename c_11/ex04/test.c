/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:07:09 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/12 14:38:49 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	comp(int a, int b)
{
	if (a < b)
		return (-1);
	if (a == b)
		return (0);
	if (a > b)
		return (1);
	return (0);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	max;

	if (!tab || !length || !f)
		return (0);
	i = -1;
	max = tab[0];
	while (++i < length - 1)
	{
		if (f(max, tab[i + 1]) > 0)
			return (0);
		else
			max = tab[i];
	}
	return (1);
}

int	main(void)
{
	int	tab[7] = {0,0,2,3,0,5,6};
	printf("sorted: %d\n", ft_is_sort(tab, 7, &comp));
	return (0);
}