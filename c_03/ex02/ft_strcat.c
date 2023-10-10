/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:07:01 by jnenczak          #+#    #+#             */
/*   Updated: 2023/09/23 23:16:51 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_str_len(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;
	int	j;

	if (get_str_len(src) == 0)
		return (dest);
	i = 0;
	dest_len = get_str_len(dest);
	j = i + dest_len;
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
