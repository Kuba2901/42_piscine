/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:08:21 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/09 23:11:52 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	check_separator(char *str, char *charset)
{
	int	i;

	i = -1;
	while (charset[i++])
		if (charset[i] == *str)
			return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int		word_count;
	int		i;
	int		sep_len;
	char	*temp;

	i = -1;
	word_count = 0;
	temp = str;
	while (charset[++i])
		;
	sep_len = i;
	while (*str)
	{
		if (*str == *charset && check_separator(str, charset))
			word_count++;
		str++;
	}
	str = temp;
	return (word_count + 1);
}

char	*create_word(char *start, char *str)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)malloc((str - start + 2));
	while (start != str)
	{
		ret[i++] = *start;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}

void	allocate_split_init_var(int *string_index, char **start)
{
	*string_index = 0;
	*start = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	char	*start;
	int		string_index;

	if (str == NULL || charset == NULL)
		return (0);
	split = (char **)malloc((count_words(str, charset) + 1) * 8);
	allocate_split_init_var(&string_index, &start);
	while (*str)
	{
		if (!start)
			start = str;
		if (check_separator(str, charset))
		{
			if (str - start)
				split[string_index++] = create_word(start, str);
			start = 0;
		}
		else if (!(*(str + 1)))
			split[string_index++] = create_word(start, str + 1);
		str++;
	}
	split[string_index] = 0;
	return (split);
}
