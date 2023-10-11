/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:30:58 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/11 22:44:54 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		add(int val1, int val2);
int		subtract(int val1, int val2);
int		divide(int val1, int val2);
int		multiply(int val1, int val2);
int		modulo(int val1, int val2);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

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

void	assign_operations(int (*operation[5])(int, int))
{
	operation[0] = &add;
	operation[1] = &subtract;
	operation[2] = &multiply;
	operation[3] = &divide;
	operation[4] = &modulo;
}

void	handle_safe(int val1, char *op,
		int val2, int (*operation[5])(int, int))
{
	if (!ft_strcmp(op, "+"))
		ft_putnbr(operation[0](val1, val2));
	else if (!ft_strcmp(op, "-"))
		ft_putnbr(operation[1](val1, val2));
	else if (!ft_strcmp(op, "*"))
		ft_putnbr(operation[2](val1, val2));
}

void	ft_do_op(int val1, char *op, int val2)
{
	int	(*operation[5])(int, int);

	assign_operations(operation);
	if (!ft_strcmp(op, "+") || !ft_strcmp(op, "-") || !ft_strcmp(op, "*"))
		handle_safe(val1, op, val2, operation);
	else if (!ft_strcmp(op, "/"))
	{
		if (!val2)
		{
			ft_putstr("Stop: division by zero\n");
			return ;
		}
		ft_putnbr(operation[3](val1, val2));
	}
	else if (!ft_strcmp(op, "%"))
	{
		if (!val2)
		{
			ft_putstr("Stop: modulo by zero\n");
			return ;
		}
		ft_putnbr(operation[4](val1, val2));
	}
	else
		ft_putstr("0");
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (1);
	ft_do_op(ft_atoi(av[1]), av[2], ft_atoi(av[3]));
	return (0);
}
