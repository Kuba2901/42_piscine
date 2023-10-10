/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:21:15 by jnenczak          #+#    #+#             */
/*   Updated: 2023/09/23 23:26:09 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	get_str_len(char *str)
{
	unsigned int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	dest_len;
	int				j;

	if (get_str_len(src) == 0)
		return (dest);
	i = 0;
	dest_len = get_str_len(dest);
	j = i + dest_len;
	while (src[i] != '\0' && i < nb)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
