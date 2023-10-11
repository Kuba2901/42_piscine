/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:49:57 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/11 23:31:33 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*ret;

	if (!tab || !f)
		return (0);
	i = -1;
	ret = (int *)malloc(sizeof(int) * length);
	while (++i < length)
		ret[i] = f(tab[i]);
	return (ret);
}
