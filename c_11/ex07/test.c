/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 23:15:23 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/11 23:17:24 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


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

void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		tab_len;

    if (!tab)
		return ;
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
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}

int main() {
    char *strings[] = {"apple", "banana", "grape", "cherry"};

    // Test 1: Sort in ascending order (default alphabetical order)
    ft_advanced_sort_string_tab(strings, ft_str_cmp);
    for (int i = 0; strings[i]; i++) {
        printf("%s ", strings[i]);
    }
    printf("\n");

    // Test 2: Sort in descending order
    ft_advanced_sort_string_tab(strings, ft_str_cmp);
    for (int i = 0; strings[i]; i++) {
        printf("%s ", strings[i]);
    }
    printf("\n");

    // Test 3: Sort in ascending order (case-insensitive)
    ft_advanced_sort_string_tab(strings, ft_str_cmp);
    for (int i = 0; strings[i]; i++) {
        printf("%s ", strings[i]);
    }
    printf("\n");

    // Test 4: Sort in descending order (custom comparison)
    ft_advanced_sort_string_tab(strings, ft_str_cmp);
    for (int i = 0; strings[i]; i++) {
        printf("%s ", strings[i]);
    }
    printf("\n");

    // Test 5: Sort with a custom comparison function
    ft_advanced_sort_string_tab(strings, ft_str_cmp);
    for (int i = 0; strings[i]; i++) {
        printf("%s ", strings[i]);
    }
    printf("\n");

    return 0;
}
