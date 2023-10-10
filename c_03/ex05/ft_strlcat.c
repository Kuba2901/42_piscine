/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 00:06:03 by jnenczak          #+#    #+#             */
/*   Updated: 2023/09/26 18:27:46 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	get_str_len(char *str)
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dst_len;
	unsigned int	characters_to_append;
	int				j;

	dst_len = get_str_len(dest);
	if (size == 0 || dst_len >= size)
		return (0);
	i = 0;
	j = dst_len;
	characters_to_append = size - dst_len;
	while (i < characters_to_append && i < get_str_len(src))
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (j);
}
