/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 01:32:31 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/09 20:05:44 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

int	get_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*copy_string(char *str)
{
	char	*string_copy;
	int		str_len;	
	int		i;

	str_len = get_str_len(str);
	string_copy = (char *)malloc((str_len + 1) * sizeof(char));
	if (string_copy == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		string_copy[i] = str[i];
		i++;
	}
	string_copy[i] = '\0';
	return (string_copy);
}

struct s_stock_str	create_struct(char *str)
{
	struct s_stock_str	s_struct;

	s_struct.size = get_str_len(str);
	s_struct.str = str;
	s_struct.copy = copy_string(str);
	return (s_struct);
}

void	add_last_struct(struct s_stock_str *arr, int i)
{
	struct s_stock_str	last;

	last.size = 0;
	last.str = 0;
	last.copy = 0;
	arr[i] = last;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*ret_strs;	
	unsigned int		size_of_struct;

	size_of_struct = sizeof(struct s_stock_str);
	ret_strs = (struct s_stock_str *)malloc((ac + 1) * size_of_struct);
	if (ret_strs == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		ret_strs[i] = create_struct(av[i]);
		i++;
	}
	add_last_struct(ret_strs, i);
	return (ret_strs);
}
