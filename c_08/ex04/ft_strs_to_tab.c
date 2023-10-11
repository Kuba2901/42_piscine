/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 01:32:31 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/11 14:15:34 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

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
	ret_strs[i].str = 0;
	return (ret_strs);
}
