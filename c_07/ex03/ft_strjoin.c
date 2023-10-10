/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:24:33 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/09 23:07:24 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_strcpy(int *main_begin, char *dest, char *src)
{
	int	i;

	i = 0;
	if (src == 0 || dest == 0)
		return ;
	while (src[i])
	{
		dest[*main_begin] = src[i];
		i++;
		*main_begin += 1;
	}
}

int	get_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_sum_len(char **strs, int size, char *sep)
{
	int	i;
	int	sep_len;
	int	sep_count;
	int	sum_len;

	i = 0;
	sum_len = 0;
	sep_len = get_str_len(sep);
	if (size > 2)
		sep_count = size / 2 + 1;
	else
		sep_count = size / 2;
	while (i < size)
	{
		sum_len += get_str_len(strs[i]);
		i++;
	}
	return (sum_len + sep_len * sep_count);
}

int	init_variables_handle_size_0(int *i, int *j, int size, char **joined)
{
	*i = -1;
	*j = 0;
	if (!size)
	{
		*joined = (char *)malloc(4);
		*joined[0] = '\0';
		return (0);
	}
	return (1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	char	*joined;
	int		main_index;
	int		sep_count;

	if (!init_variables_handle_size_0(&i, &j, size, &joined) || sep == 0)
		return (joined);
	joined = (char *)malloc(get_sum_len(strs, size, sep) * 4);
	if (!joined)
		return (0);
	if (size > 1)
		sep_count = size - 1;
	else
		sep_count = 0;
	main_index = 0;
	while (++i < size + sep_count)
	{
		if (i != 0 && i % 2 != 0)
			ft_strcpy(&main_index, joined, sep);
		else
			ft_strcpy(&main_index, joined, strs[j++]);
	}
	joined[main_index] = '\0';
	return (joined);
}
