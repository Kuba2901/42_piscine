/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:26:30 by jnenczak          #+#    #+#             */
/*   Updated: 2023/09/25 19:35:10 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	is_low_case(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	first;
	int	i;

	first = 1;
	i = 0;
	if (str == 0)
		return (str);
	while (str[i] != '\0')
	{
		if (!is_number(str[i]) && !is_alpha(str[i]))
			first = 1;
		if (first)
		{
			if (is_alpha(str[i]) || is_number(str[i]))
			{
				if (is_low_case(str[i]))
					str[i] = str[i] - 32;
				first = 0;
			}
		}
		else if (!first && is_alpha(str[i]) && !is_low_case(str[i]))
			str[i] += 32;
		i++;
	}
	return (str);
}
