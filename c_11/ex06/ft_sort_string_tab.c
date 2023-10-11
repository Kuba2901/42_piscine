#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
} 
 
void	ft_sort_string_tab(char **tab)
{
	char	*temp;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (tab[++i])
		;
	i++;
	while (++j < --i)
	{
		if (ft_strcmp(tab[j], tab[i]))
		{
			temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
		}
	}
}

int	main(int ac, char **av)
{
	ft_sort_string_tab(av + 1);
	av--;
	while (*(++av))
		printf("%s\n", *av);
	return (0);
}