 int	ft_str_cmp(char *s1, char *s2)
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
	int		i;
	int		j;
	char	*temp;
	int		tab_len;

	i = 0;
	j = 0;
	tab_len = -1;
	while (tab[++tab_len])
		;
	while (i < tab_len)
	{
		j = 0;
		while (j < tab_len - 1)
		{
			if (ft_str_cmp(tab[j], tab[j + 1]) > 0)
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

 
 void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
 {
    
 }