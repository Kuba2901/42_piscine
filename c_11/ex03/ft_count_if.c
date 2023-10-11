/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:53:11 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/11 23:31:44 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	counter;
	int	i;

	if (!tab || !f)
		return (0);
	counter = 0;
	i = -1;
	while (++i < length)
		counter += f(tab[i]);
	return (counter);
}
