/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:52:30 by jnenczak          #+#    #+#             */
/*   Updated: 2023/09/26 19:13:55 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	get_start_index(char *str);

int	count_minus_signs(char *str)
{
	int	i;
	int	minus_count;

	minus_count = 0;
	i = get_start_index(str);
	while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			minus_count++;
		i++;
	}
	return (minus_count);
}

int	get_start_index(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	return (i);
}

int	count_skipped(char *str)
{
	int	i;

	i = get_start_index(str);
	while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	num;
	int	i;
	int	minus_count;

	minus_count = count_minus_signs(str);
	num = 0;
	i = count_skipped(str);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			break ;
		num = 10 * num + str[i] - 48;
		i++;
	}
	if (minus_count % 2 != 0)
		return (-num);
	return (num);
}
