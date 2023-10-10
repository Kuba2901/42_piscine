/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:39:30 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/02 16:41:52 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	output_num(int num)
{
	char	a;
	char	b;

	if (num <= 9)
	{
		a = '0';
		b = num + 48;
	}
	else
	{
		a = num / 10 + 48;
		b = num % 10 + 48;
	}
	write(1, &a, 1);
	write(1, &b, 1);
}

void	output_string(int num1, int num2)
{
	output_num(num1);
	write(1, " ", 1);
	output_num(num2);
	if (!(num1 == 98 && num2 == 99))
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < 99)
	{
		while (j < 100)
		{
			output_string(i, j);
			if (j == 99)
			{
				i++;
				j = i + 1;
			}
			else
			{
				j++;
			}
		}
	}
}
