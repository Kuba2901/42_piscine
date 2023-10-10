/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:27:58 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/03 12:44:53 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_correct(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str == 0 || str[i] == '\0')
		return (0);
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j] || str[j] == ' ')
				return (0);
			if (str[j] == '+' || str[j] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	find_base_num(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	find_index_in_base(char a, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == a)
			return (i);
		i++;
	}
	return (-1);
}

int	find_num_start(char *str, char *base)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (find_index_in_base(str[i], base) != -1)
			return (i);
		i++;
	}
	return (-1);
}

long long	ft_atoi_base(char *str, char *base)
{
	int			i;
	long long	num;
	int			base_num;
	int			index_in_base;

	base_num = find_base_num(base);
	num = 0;
	i = find_num_start(str, base);
	while (str[i])
	{
		index_in_base = find_index_in_base(str[i], base);
		if (index_in_base == -1)
			break ;
		num = num * base_num + index_in_base;
		i++;
	}
	return (num);
}
