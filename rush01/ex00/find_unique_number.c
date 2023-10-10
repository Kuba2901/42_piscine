/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_unique_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:31:20 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/01 20:32:39 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int	find_unique_number_in_row(int border_len, int row, int **tab)
{
	int	i;
	int	j;
	int	exists;

	i = 1;
	j = 1;
	exists = 0;
	while (i < border_len - 1)
	{
		j = i;
		while (j < border_len - 1)
		{
			if (tab[row][j] == i)
			{
				exists = 1;
				break ;
			}
			j++;
		}
		if (!exists)
			return (i);
		exists = 0;
		i++;
	}
	return (i);
}
*/
