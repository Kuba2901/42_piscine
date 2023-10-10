/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:59:21 by jnenczak          #+#    #+#             */
/*   Updated: 2023/09/27 16:59:22 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	fac;
	int	i;

	if (!nb)
		return (1);
	if (nb < 0)
		return (0);
	fac = 1;
	i = 0;
	while (i < nb)
	{
		fac *= nb - i;
		i++;
	}
	return (fac);
}
