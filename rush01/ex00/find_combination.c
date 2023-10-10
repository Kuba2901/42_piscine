/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_combination.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:33:23 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/03 13:17:07 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_correct(int border_len, int **tab);
void	print_tab(int no_border, int border_len, int **tab);

void	init_combination_variables(int *i, int *j, int *k)
{
	*i = 1;
	*j = 1;
	*k = 1;
}

int	find_combination(int border_len, int **tab)
{
	int	i;
	int	j;
	int	k;

	init_combination_variables(&i, &j, &k);
	if (check_correct(border_len, tab) == 1)
		return (1);
	print_tab(0, border_len, tab);
	while (i < border_len - 1)
	{
		while (j < border_len - 1)
		{
			if (tab[i][j] == 0)
			{
				if (k == border_len - 2)
					k = 1;
				while (k < border_len - 1)
				{
					tab[i][j] = k;
					if (find_combination(border_len, tab) == 1)
						return (1);
					else
					{
						tab[i][j] = 0;
						k++;
					}
				}
			}
			j++;
		}
		j = 1;
		i++;
	}
	return (0);
}
