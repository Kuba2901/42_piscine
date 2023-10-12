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

	if (!tab || !f)
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

	if (!tab || !f)
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
	return (ft_is_sort_asc(tab, length, f) || ft_is_sort_desc(tab, length, f));
}

int main(void)
{
    int tab1[7] = {0, 1, 2, 3, 4, 5, 6};
    printf("sorted: %d\n", ft_is_sort(tab1, 7, &comp)); // 1 (ascending)

    int tab2[7] = {6, 5, 4, 3, 2, 1, 0};
    printf("sorted: %d\n", ft_is_sort(tab2, 7, &comp)); // 1 (descending)

    int tab3[7] = {0, 1, 2, 2, 3, 4, 5};
    printf("sorted: %d\n", ft_is_sort(tab3, 7, &comp)); // 1 (ascending with equal elements)

    int tab4[1] = {1};
    printf("sorted: %d\n", ft_is_sort(tab4, 1, &comp)); // 1 (single element array)

    int tab5[0] = {};
    printf("sorted: %d\n", ft_is_sort(tab5, 0, &comp)); // 1 (empty array)

    int tab6[2] = {2, 1};
    printf("sorted: %d\n", ft_is_sort(tab6, 2, &comp)); // 1 (descending)

    int tab7[5] = {0, 1, 2, 3, 2};
    printf("sorted: %d\n", ft_is_sort(tab7, 5, &comp)); // 0 (not strictly ascending)

    int tab8[5] = {3, 3, 3, 3, 3};
    printf("sorted: %d\n", ft_is_sort(tab8, 5, &comp)); // 1 (equal elements)

    int tab9[2] = {1, 1};
    printf("sorted: %d\n", ft_is_sort(tab9, 2, &comp)); // 1 (equal elements)

    int tab10[7] = {0, 0, 0, 0, 0, 0, 0};
    printf("sorted: %d\n", ft_is_sort(tab10, 7, &comp)); // 1 (all equal elements)

    return (0);
}