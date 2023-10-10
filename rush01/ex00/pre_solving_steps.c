/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_solving_steps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:50:04 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/01 23:38:49 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	go_up_down(int border_len, int i, int j, int **tab);
void	go_down_up(int i, int j, int **tab);
void	go_left_right(int border_len, int **tab, int *i, int *j);
void	go_right_left(int border_len, int **tab, int *i, int *j);

void	init_variables(int *i, int *j, int *k)
{
	*i = 1;
	*j = 1;
	*k = 1;
}

void	go_sideways(int border_len, int **tab)
{
	int	i;
	int	j;
	int	k;

	init_variables(&i, &j, &k);
	while (i < border_len - 1)
	{
		while (j < border_len - 1)
		{
			if (tab[i][j - 1] == 1 || tab[i][j + 1] == 1)
				tab[i][j] = border_len - 2;
			else if (tab[i][j - 1] == border_len - 2 && j == 1)
				go_left_right(border_len, tab, &i, &j);
			else if (tab[i][j + 1] == border_len - 2)
			{
				go_right_left(border_len, tab, &i, &j);
				break ;
			}
			j++;
		}
		j = 1;
		i++;
	}
}

void	fill_highest_lowest(int border_len, int **tab)
{
	int	i;
	int	j;
	int	k;

	go_sideways(border_len, tab);
	init_variables(&i, &j, &k);
	while (i < border_len - 1)
	{
		while (j < border_len - 1)
		{
			if (i == 1 || i == border_len - 2)
			{
				if (tab[i - 1][j] == 1 || tab[i + 1][j] == 1)
					tab[i][j] = border_len - 2;
				else if (tab[i - 1][j] == border_len - 2)
					go_up_down(border_len, i, j, tab);
				else if (tab[i + 1][j] == border_len - 2)
					go_down_up(i, j, tab);
			}
			j++;
		}
		i++;
	}
}
