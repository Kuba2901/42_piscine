/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:30:58 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/11 20:30:37 by jnenczak         ###   ########.fr       */
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

int	add(int val1, int val2)
{
	return (val1 + val2);
}

int	subtract(int val1, int val2)
{
	return (val1 - val2);
}

int	divide(int val1, int val2)
{
	return (val1 / val2);
}

int	multiply(int val1, int val2)
{
	return (val1 * val2);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_putnbr(int nb)
{
	char	a;

	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}
	else if (nb <= 9)
	{
		a = nb + 48;
		write(1, &a, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_do_op(int val1, char *op, int val2)
{
	void (*operation[])(int, int) = {&add, &subtract, &multiply, &divide};
	if (!ft_strcmp(op, "+"))
		ft_putnbr(operation[0](val1, val2));
	else if (!ft_strcmp(op, "-"))
		ft_putnbr(operation[0](val1, val2));	else if (!ft_strcmp(op, "*"))
		return (operation[1](val1, val2));
	else if (!ft_strcmp(op, "/"))
	{
		if (!val2)
		{
			ft_putstr("Stop: division by zero");
			return ;
		}
		return (operation[3](val1, val2));
	}
	else if (!ft_strcmp(op, "%"))
	{
		if (!val2)
		{
			ft_putstr("Stop: modulo by zero");
			return ;
		}
		return (operation[4](val1, val2));
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	printf("%d\n", ft_atoi(av[1]));
	return (0);
}
