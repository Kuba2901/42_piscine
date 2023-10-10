/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:43:36 by jnenczak          #+#    #+#             */
/*   Updated: 2023/09/24 21:47:41 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);
void	new_line_increment_i(int *i);
void	assign_char_array(char tab[4][6]);
void	assign_char_array2(char tab[4][6]);
void	generate_top_or_bottom(int i, int n, int j, char tab[6]);

void	top_row(int n, int j, char tab[6])
{
	char	tl;
	char	tr;
	char	hs;

	tr = tab[2];
	tl = tab[0];
	hs = tab[4];
	if (j == 0)
		ft_putchar(tl);
	else if (j == n - 1)
		ft_putchar(tr);
	else
		ft_putchar(hs);
}

void	mid_row(int n, int j, char vs)
{
	if (j == 0 || j == n - 1)
		ft_putchar(vs);
	else
		ft_putchar(' ');
}

void	last_row(int n, int j, char tab[6])
{
	char	bl;
	char	br;
	char	hs;

	bl = tab[1];
	br = tab[3];
	hs = tab[4];
	if (j == 0)
		ft_putchar(bl);
	else if (j == n - 1)
		ft_putchar(br);
	else
		ft_putchar(hs);
}

void	assign_array_init_i_y(int *i, int *y, char tab[4][6])
{
	assign_char_array(tab);
	assign_char_array2(tab);
	*i = 0;
	*y = 0;
}

void	rush(int x, int y)
{
	int		i;
	int		j;
	char	tab[5][6];
	int		tab_y;

	assign_array_init_i_y(&i, &tab_y, tab);
	while (tab_y < 5)
	{
		while (i < y)
		{
			j = 0;
			while (j < x)
			{
				if (i == 0 || i == y - 1)
					generate_top_or_bottom(i, x, j, tab[tab_y]);
				else
					mid_row(x, j, tab[tab_y][5]);
				j++;
			}
			new_line_increment_i(&i);
		}
		ft_putchar('\n');
		tab_y++;
		i = 0;
	}
}
