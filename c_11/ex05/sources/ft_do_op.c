/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:30:58 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/11 23:32:00 by jnenczak         ###   ########.fr       */
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
int		ft_atoi(char *str);

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

int	safe(char *op)
{
	return ((!ft_strcmp(op, "+") || !ft_strcmp(op, "-") \
				|| !ft_strcmp(op, "*")));
}

void	ft_do_op(int val1, char *op, int val2)
{
	int	(*operation[5])(int, int);

	assign_operations(operation);
	if (op && safe(op))
		handle_safe(val1, op, val2, operation);
	else if (op && !ft_strcmp(op, "/"))
	{
		if (!val2)
		{
			ft_putstr("Stop: division by zero");
			return ;
		}
		ft_putnbr(operation[3](val1, val2));
	}
	else if (op && !ft_strcmp(op, "%"))
	{
		if (!val2)
		{
			ft_putstr("Stop: modulo by zero");
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
