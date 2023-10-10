/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:04:55 by jnenczak          #+#    #+#             */
/*   Updated: 2023/09/24 13:52:48 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	top_row(int n, int j, char tl, char hs, char tr)
{
	if (j == 0)
		ft_putchar(tl);

	if (j == n - 1)
	{
		ft_putchar(tr);
	}
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

void	last_row(int n, int j, char bl, char hs, char br)
{
	if (j == 0) 
		ft_putchar(bl);
	else if (j == n - 1)
		ft_putchar(br);
	else
		ft_putchar(hs);
}

void	new_line_increment_i(int *i)
{
	*i = *i + 1;
	ft_putchar('\n');
}

void	assign_char_tab_values(char char_tab[4][6])
{
	char_tab[0][0] = '/';
	char_tab[0][1] = '\\';
	char_tab[0][2] = '\\';
	char_tab[0][3] = '/';
	char_tab[0][4] = '*';
	char_tab[0][5] = '*';
	char_tab[1][0] = 'o';
	char_tab[1][1] = 'o';
	char_tab[1][2] = 'o';
	char_tab[1][3] = 'o';
	char_tab[1][4] = '|';
	char_tab[1][5] = '-';
	char_tab[2][0] = 'A';
	char_tab[2][1] = 'C';
	char_tab[2][2] = 'A';
	char_tab[2][3] = 'C';
	char_tab[2][4] = 'B';
	char_tab[2][5] = 'B';
	char_tab[3][0] = 'A';
	char_tab[3][1] = 'A';
	char_tab[3][2] = 'C';
	char_tab[3][3] = 'C';
	char_tab[3][4] = 'B';
	char_tab[3][5] = 'B';
}

void	rush(int n, int m)
{
	
	char	char_tab[4][6];
	int		i;
	int		j;
	int		char_tab_y;
	char	tl;
	char	bl;
	char	tr;
	char	br;
	char	vs;
	char	hs;

	i = 0;
	assign_char_tab_values(char_tab);
	char_tab_y = 0;
	while (char_tab_y < 5)
	{
		tl = char_tab[char_tab_y][0];
		bl = char_tab[char_tab_y][1];
		tr = char_tab[char_tab_y][2];
		br = char_tab[char_tab_y][3];
		vs = char_tab[char_tab_y][4];
		hs = char_tab[char_tab_y][5];
		
		while (i < m)
		{
			j = 0;
			while (j < n)
			{
				if (i == 0)
				{
					top_row(n, j, tl, hs, tr);
				}
				else if (i < m - 1)
				{
					mid_row(n, j, vs);
				}
				else
				{
					last_row(n, j, bl, hs, br);
				}
				j++;
			}
			new_line_increment_i(&i);
		}	

		ft_putchar('\n');
		char_tab_y++;
	}


}
