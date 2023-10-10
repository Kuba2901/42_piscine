/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:43:51 by fde-sist          #+#    #+#             */
/*   Updated: 2023/09/23 13:53:27 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	top_row(int n, int j)
{
	if (j == 0 || j == n - 1)
	{
		ft_putchar('o');
	}
	else
		ft_putchar('-');
}

void	mid_row(int n, int j)
{
	if (j == 0 || j == n - 1)
		ft_putchar('|');
	else
		ft_putchar(' ');
}

void	last_row(int n, int j)
{
	if (j == 0 || j == n - 1)
		ft_putchar('o');
	else
		ft_putchar('-');
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
