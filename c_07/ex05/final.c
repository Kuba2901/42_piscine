#include <stdlib.h>

int	is_sep(char *str, char *charset)
{
	if (*str == '\0')
		return (1);
	while (*charset)
	{
		if (*str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	char	*temp;
	char	*beg;
	int		wc;

	wc = 0;
	beg = str;
	while (*str)
	{
		temp = str;
		while (str != beg && is_sep(str, charset))
			str++;
		if (str - temp)
			wc++;
		str++;
	}
	return (wc);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;

	if (str == NULL)
	{
		split = (char **)malloc(sizeof(char *));
		split[0] = 0;
		return (split);
	}
	printf("wc: %d\n", count_words(str, charset));
}
