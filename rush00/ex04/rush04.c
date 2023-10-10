/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:25:45 by adi-nisi          #+#    #+#             */
/*   Updated: 2023/09/23 15:55:44 by adi-nisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	top_row(int n, int j)
{
	if (j == 0)
		ft_putchar('A');
	else if (j == n - 1)
		ft_putchar('C');
	else
		ft_putchar('B');
}

void	mid_row(int n, int j)
{
	if (j == 0 || j == n - 1)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	last_row(int n, int j)
{
	if (j == 0)
		ft_putchar('C');
	else if (j == n - 1)
		ft_putchar('A');
	else
		ft_putchar('B');
}

void	new_line_increment_i(int *i)
{
	*i = *i + 1;
	ft_putchar('\n');
}

void	rush(int n, int m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m)
	{
		j = 0;
		while (j < n)
		{
			if (i == 0)
			{
				top_row(n, j);
			}
			else if (i < m - 1)
			{
				mid_row(n, j);
			}
			else
			{
				last_row(n, j);
			}
			j++;
		}
		new_line_increment_i(&i);
	}
}
