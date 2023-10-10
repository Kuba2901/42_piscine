/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:33:57 by jnenczak          #+#    #+#             */
/*   Updated: 2023/09/26 12:45:49 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_non_printable(char c)
{
	if (c <= 31 || c >= 127)
		return (1);
	return (0);
}

void	char_to_hex(char c)
{
	int		div;
	int		mod;
	char	*hex_alpha_values;
	char	a;

	div = c / 16 + '0';
	mod = c % 16;
	hex_alpha_values = "0123456789abcdef";
	a = hex_alpha_values[mod];
	write(1, "\\", 1);
	write(1, &div, 1);
	write(1, &a, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (is_non_printable(c))
		{
			char_to_hex(c);
		}
		else
			write(1, &c, 1);
		i++;
	}
}
