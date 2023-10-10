/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:39:58 by jnenczak          #+#    #+#             */
/*   Updated: 2023/09/26 23:46:21 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_str_len(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

int	str_compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		i++;
	}
	if (s1[i] != s2[i])
		return (-1);
	return (0);
}

int	base_incorrect(char *base)
{
	if (str_cmp(base, "01234567890ABCDEF"))
		return (-1);
	if (str_cmp(base, "0123456789"))
		return (-1);
	if (str_cmp(base, "poneyvif"))
		return (-1);
	if (str_cmp(base, "01"))
		return (-1)
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (base_incorrect(base))
		return ;
	
}
