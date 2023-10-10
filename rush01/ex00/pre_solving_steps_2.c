/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_solving_steps_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:48:24 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/01 23:42:46 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	go_up_down(int border_len, int i, int j, int **tab)
{
	int	k;
	int	up_down;

	up_down = i;
	k = 1;
	while (up_down < border_len - 1)
	{
		tab[up_down][j] = k++;
		up_down++;
	}
}

void	go_down_up(int i, int j, int **tab)
{
	int	k;
	int	up_down;

	k = 1;
	up_down = i;
	while (up_down > 0)
	{
		tab[up_down][j] = k++;
		up_down--;
	}
}

void	go_left_right(int border_len, int **tab, int *i, int *j)
{
	int	k;

	k = 1;
	while (*j < border_len - 1)
	{
		tab[*i][*j] = k;
		k += 1;
		*j += 1;
	}
}

void	go_right_left(int border_len, int **tab, int *i, int *j)
{
	int	k;

	border_len -= 1;
	k = 1;
	while (j > 0)
	{
		tab[*i][*j] = k++;
		*j -= 1;
	}
}
