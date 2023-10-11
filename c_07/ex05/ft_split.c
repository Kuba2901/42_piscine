/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:06:55 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/11 16:08:20 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_sep(char *str, char *charset)
{
	while (*charset)
	{
		if (*str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset, int str_len)
{
	int		wc;
	int		jumped;
	int		i;
	char	*con;

	wc = 0;
	i = 0;
	con = str;
	while (*str)
	{
		jumped = 0;
		while (is_sep(str, charset))
		{
			jumped++;
			str++;
			if (!(*str))
				return (wc);
		}
		if (!(con - str) || jumped)
			wc++;
		str++;
	}
	return (wc);
}

char	*create_word(char *str, char *charset)
{
	char	*created;
	int		i;
	int		word_len;

	word_len = 0;
	while (*(str + word_len) && !is_sep(str + word_len, charset))
		word_len++;
	i = -1;
	created = (char *)malloc(word_len + 1);
	while (++i < word_len)
	{
		created[i] = *str;
		str++;
	}
	created[i] = '\0';
	return (created);
}

int	handle_errors(char *str, char *charset, char ***split, int *string_index)
{
	int	str_len;

	if (str == NULL)
	{
		*split = (char **)malloc(1 * 8);
		(*split)[0] = 0;
		return (0);
	}
	str_len = -1;
	while (str[++str_len])
		;
	if (charset == NULL)
	{
		*split = (char **)malloc(2 * 8);
		(*split)[0] = (char *)malloc(str_len + 1);
		(*split)[0] = create_word(str, "");
		(*split)[1] = 0;
		return (1);
	}
	*split = (char **)malloc(
			(count_words(str, charset, str_len) + 1) * sizeof(char *));
	*string_index = 0;
	(*split)[count_words(str, charset, str_len)] = 0;
	return (2);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	char	*start;
	char	*jumped;
	int		string_index;

	if (handle_errors(str, charset, &split, &string_index) != 2)
		return (split);
	while (*(str))
	{
		while (*str && is_sep(str, charset))
			str++;
		if (*str)
			split[string_index++] = create_word(str, charset);
		while (*str && !is_sep(str, charset))
			str++;
	}
	split[string_index] = 0;
	return (split);
}
