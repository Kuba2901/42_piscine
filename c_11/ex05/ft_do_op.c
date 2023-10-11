/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:30:58 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/11 20:16:32 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	num;
	int	minus_count;

	num = 0;
	minus_count = 0;
	while (*str < '0' || *str > '9')
	{
		if (*str != '-' && *str != ' ' && *str != '+')
			return (0);
		if (*str == '-')
			minus_count++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	if (minus_count % 2 != 0)
		return (-num);
	return (num);
}

int	ft_do_op(int val1, char *op, int val2, int (*f)(int

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	printf("%d\n", ft_atoi(av[1]));
	return (0);
}
