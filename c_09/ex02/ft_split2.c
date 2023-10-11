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
	int	wc;
	int	jumped;
	int	i;
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
		(*split)[0] = str;
		(*split)[1] = 0;
		return (1);
	}
	*split = (char **)malloc((count_words(str, charset, str_len) + 1) * sizeof(char *));
	*string_index = 0;
	(*split)[count_words(str, charset, str_len)] = 0;
	return (2);
}

char	*create_word(char *start, char *end, char *charset)
{
	char	*created;
	int		i;
	int		str_len;

	str_len = -1;
	i = 0;
	// if (is_sep(start - 1, charset) && !(*(start + 1)))
	// 	start--;
	created = (char *)malloc(end - start + 2);
	while (start != end)
	{
		created[i++] = *start;
		start++;
	}
	created[i] = '\0';
	return (created);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	char	*start;
	char	*jumped;
	int		string_index;

	if (handle_errors(str--, charset, &split, &string_index) != 2)
		return (split);
	start = 0;
	while (*(++str))
	{
		jumped = str;
		while (is_sep(str, charset))
			str++;
		printf("creating a word: %s\n", start);
		if (start && ((jumped - str) || !(*(str + 1))))
		{
			if (is_sep(str, charset) && (!(*str) || !(*(str + 1))))
				break ;
			split[string_index++] = create_word(start, jumped, charset);
			if (!is_sep(str, charset) && (!(*str) || !(*(str + 1))))
				break ;
			start = str;
		}
		if (!start)
			start = str;
	}
	return (split);
}

int	main(int ac, char **av)
{
	int		i;
	char	**split;

	split = ft_split("hello worl d", " ");
	// split = ft_split(av[1], av[2]);
	i = -1;
	while (split[++i])
		printf("%s\n", split[i]);
	return (0);
}