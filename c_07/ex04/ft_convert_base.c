/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:44:02 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/09 23:11:36 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			base_correct(char *str);
int			find_num_start(char *str, char *base);
int			find_base_num(char *base);
long long	ft_atoi_base(char *str, char *base);

char	*write_inverted_string(long long nb, char *n_num, int *r_i, char *b_t)
{
	int	remainder;
	int	base_num;

	remainder = 0;
	base_num = find_base_num(b_t);
	while (nb != 0)
	{
		remainder = nb % base_num;
		n_num[*r_i] = b_t[remainder];
		nb /= base_num;
		*r_i += 1;
	}
	n_num[*r_i] = '\0';
	return (n_num);
}

char	*invert_num(int i, int j, char *new_num)
{
	char	temp;

	while (i < j)
	{
		temp = new_num[i];
		new_num[i] = new_num[j];
		new_num[j] = temp;
		i++;
		j--;
	}
	return (new_num);
}

char	*convert_to_base(long long nb, char *base_to, int negative)
{
	int		res_index;
	char	*new_num;

	res_index = 0;
	new_num = (char *)malloc(64);
	if (negative)
		res_index++;
	else if (nb == 0)
	{
		new_num[res_index++] = base_to[0];
		new_num[res_index++] = '\0';
		return (new_num);
	}
	write_inverted_string(nb, new_num, &res_index, base_to);
	invert_num(negative, res_index - 1, new_num);
	if (negative)
		new_num[0] = '-';
	return (new_num);
}

int	count_minus(char *nbr, char *base)
{
	int	num_begin;
	int	i;
	int	minus_count;

	num_begin = find_num_start(nbr, base);
	i = 0;
	minus_count = 0;
	while (i < num_begin)
	{
		if (nbr[i] == '-')
			minus_count++;
		i++;
	}
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			minus_count;
	long long	num_value;

	if (nbr == NULL || !nbr[0] || base_from == NULL || base_to == NULL)
		return (0);
	minus_count = count_minus(nbr, base_from);
	if (!base_correct(base_from) || !base_correct(base_to))
		return (0);
	num_value = ft_atoi_base(nbr, base_from);
	return (convert_to_base(num_value, base_to, minus_count % 2));
}
