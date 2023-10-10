/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:22:28 by fde-sist          #+#    #+#             */
/*   Updated: 2023/09/24 21:23:06 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	rush(int n, int m);
int		ft_atoi(char *str);
void	ft_putstr(char *str);

void	assign_char_array(char tab[4][6])
{
	tab[0][0] = '/';
	tab[0][1] = '\\';
	tab[0][2] = '\\';
	tab[0][3] = '/';
	tab[0][4] = '*';
	tab[0][5] = '*';
	tab[1][0] = 'o';
	tab[1][1] = 'o';
	tab[1][2] = 'o';
	tab[1][3] = 'o';
	tab[1][4] = '-';
	tab[1][5] = '|';
	tab[2][0] = 'A';
	tab[2][1] = 'C';
	tab[2][2] = 'A';
	tab[2][3] = 'C';
	tab[2][4] = 'B';
	tab[2][5] = 'B';
}

void	assign_char_array2(char tab[4][6])
{
	tab[3][0] = 'A';
	tab[3][1] = 'A';
	tab[3][2] = 'C';
	tab[3][3] = 'C';
	tab[3][4] = 'B';
	tab[3][5] = 'B';
	tab[4][0] = 'A';
	tab[4][1] = 'C';
	tab[4][2] = 'C';
	tab[4][3] = 'A';
	tab[4][4] = 'B';
	tab[4][5] = 'B';
}

int	main(int argc, char **argv)
{
	int	num1;
	int	num2;

	if (argc != 3)
	{
		ft_putstr("Wrong number of parameters was given\n");
		ft_putstr("Expected 2 positive integers.");
		return (1);
	}
	num1 = ft_atoi(argv[1]);
	num2 = ft_atoi(argv[2]);
	if (num1 == -1 || num2 == -1)
	{
		ft_putstr("At least one of the given numbers is not of valid type.\n");
		ft_putstr("Expected values of type unsigned int (positive)");
		return (1);
	}
	rush(num1, num2);
	return (0);
}

int	ft_atoi(char *str)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = 10 * num + (str[i] - 48);
		i++;
	}
	if (!num)
		return (-1);
	return (num);
}
