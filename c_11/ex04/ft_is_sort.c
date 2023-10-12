/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:07:09 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/12 15:21:21 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sort;

	sort = 1;
	i = -1;
	while (++i < length - 1 && sort)
		if ((*f)(tab[i], tab[i + 1]) < 0)
			sort = 0;
	if (!sort)
	{
		sort = 1;
		i = -1;
		while (++i < length - 1)
			if ((*f)(tab[i], tab[i + 1]) > 0)
				return (0);
	}
	return (1);
}