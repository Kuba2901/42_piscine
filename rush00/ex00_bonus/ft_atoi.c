/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 01:16:42 by jnenczak          #+#    #+#             */
/*   Updated: 2023/09/24 01:46:02 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_num_len(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			break ;
		len++;
		i++;
	}
	return (len);
}

int	raise_power(char c, int pow)
{
	int	sum;
	int	n;

	n = c - '0';
	sum = 10;
	if (pow < 0)
		return (n);
	while (pow > 0)
	{
		sum *= 10;
		pow--;
	}
	return (n * sum);
}

int	ft_atoi(char *str)
{
	int		num;
	int		i;
	int		pow;
	int		num_len;
	char	c;

	if (str[0] == '-')
		return (0);
	i = 0;
	num = 0;
	num_len = get_num_len(str);
	pow = num_len - 2;
	while (i < num_len)
	{
		c = str[i];
		num += raise_power(c, pow);
		pow--;
		i++;
	}
	return (num);
}
