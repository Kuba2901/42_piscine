#include <stdio.h>
#include <stdlib.h>

int	check_separator(char *str, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (charset[i] == *str)
			return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	word_count;

	i = -1;
	word_count = 0;
	while (str[++i])
		if (i != 0 && check_separator((str + i), charset))
			if (!check_separator((str - 1), charset))
				word_count += 1;
	return (word_count + 1);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		string_index;
	int		word_begin;

	// printf("wc: %d\n", count_words(str, charset));
	string_index = 0;
	word_begin = -1;
	split = (char **)malloc((count_words(str, charset) + 1) * 8);
	while (*str)
	{
		if (word_begin == -1)
			word_begin = str;
		if (check_separator(str, charset))
		{
			if (
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	ft_split(argv[1], argv[2]);
	return (0);
}
