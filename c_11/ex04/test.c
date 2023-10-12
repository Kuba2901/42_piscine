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

int	ft_is_sort_desc(int *tab, int length, int (*f)(int, int))
{
	int	i;

	if (!tab || !length || !f)
		return (0);
	i = -1;
	while (++i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
	}
	return (1);
}

int	ft_is_sort_asc(int *tab, int length, int (*f)(int, int))
{
	int	i;

	if (!tab || !length || !f)
		return (0);
	i = -1;
	while (++i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	return (ft_is_sort_asc(tab, length, f) + ft_is_sort_desc(tab, length, f));
}

int	main(void)
{
	int	tab[7] = {4,3,2,0,0,0};
	printf("sorted: %d\n", ft_is_sort(tab, 5, &comp));
	return (0);
}