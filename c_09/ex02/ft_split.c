#include <stdio.h>

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

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int	str_len;

	if (str == NULL)
	{
		split = (char **)malloc(1 * 8);
		split[0] = 0;
		return (split);
	}
	str_len = -1;
	while (str[++str_len])
		;
	if (charset == NULL)
	{
		split = (char **)malloc(2 * 8);
		split[0] = (char *)malloc(str_len + 1);
		*split[0] = &str;
		split[1] = 0;
		return (split);
	}
	split = (char **)malloc(count_words(str, charset, str_len) * sizeof(char *));

}
