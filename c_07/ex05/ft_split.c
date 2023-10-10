/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:08:21 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/10 17:50:16 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/*
int	check_separator(char *str, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (charset[i] == *str)
			return (1);
	return (0);
}
*/

int check_separator(char *str, char *charset) {
    int i;

    while (*charset) {
        i = 0;
        while (charset[i] == str[i] && charset[i] != '\0') {
            i++;
        }
        if (charset[i] == '\0') {
            return 1; // Found a separator
        }
        charset++;
    }

    return 0; // Not a separator
}


int	count_words(char *str, char *charset)
{
	int		word_count;
	int		i;
	int		sep_len;

	i = -1;
	word_count = 0;
	while (*str)
	{
		if (*str == *charset && check_separator(str, charset))
			word_count++;
		str++;
	}
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

	if (check_errors(str, charset, &split, &string_index) != 2)
		return (split);
	start = 0;	
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
