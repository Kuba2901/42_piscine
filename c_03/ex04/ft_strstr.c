/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:28:05 by jnenczak          #+#    #+#             */
/*   Updated: 2023/09/26 18:24:55 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_str_len(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	compare_str(char *needle, char *word, int word_index)
{
	int	same;
	int	i;
	int	j;

	same = 1;
	i = word_index;
	j = 0;
	while (j < get_str_len(needle))
	{
		if (needle[j] != word[i] || word[i] == '\0')
			return (0);
		i++;
		j++;
	}
	return (1);
}

char	needle_empty(char *to_find)
{
	int	needle_len;

	needle_len = get_str_len(to_find);
	if (needle_len > 0)
		return (to_find[0]);
	else
		return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	char	c;
	char	first_to_find;
	int		found;

	i = 0;
	found = 0;
	first_to_find = needle_empty(to_find);
	if (first_to_find == 0)
		return (str);
	while (str[i] != '\0')
	{
		c = str[i];
		if (c == first_to_find)
		{
			found = compare_str(to_find, str, i);
			if (found)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
