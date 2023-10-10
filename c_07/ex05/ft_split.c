/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:08:21 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/10 18:59:48 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_sep(char a, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (charset[i] == a)
			return (1);
	return (0);
}

int	check_sep(char *str, char *charset)
{
	char	*start;

	start = str;
	while (is_sep(*str, charset))
	{
		if (!(*str))
			break ;
		str++;
	}
	return (str - start);
}

int	count_words(char *str, char *charset)
{
	int		word_count;
	int		i;
	int		sep_len;

	i = -1;
	word_count = 0;
	while (*str)
		if (check_sep(str++, charset))
			word_count++;			
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

int	check_errors(char *str, char *charset, char ***split, int *string_index)
{
	int	str_len;

	str_len = -1;
	if (str == NULL)
	{
		*split = (char **)malloc(1 * 8);
		(*split)[0] = 0;
		return (0);
	}
	else if (charset == NULL)
	{
		while (str[++str_len])
			;
		*split = (char **)malloc(2 * 8);
		(*split)[0] = create_word(str, str + str_len - 1);
		(*split)[1] = 0;
		return (1);
	}
	*string_index = 0;
	*split = (char **)malloc((count_words(str, charset) + 1) * 8);
	return (2);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	char	*start;
	int		string_index;
	char	*temp_str;

	if (check_errors(str, charset, &split, &string_index) != 2)
		return (split);
	start = 0;	
	while (*str)
	{
		if (!start)
			start = str;
		temp_str = str;
		str += check_sep(str, charset);
		if (str - temp_str)
		{
			printf("diff: %d, start: %s, str: %s\n", temp_str - start, temp_str, str);
			split[string_index++] = create_word(start, temp_str);
			start = 0;
		}
		else
			str++;
	}
	split[string_index] = 0;
	return (split);
}
