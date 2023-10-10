/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:59:06 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/02 17:43:47 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_variables(unsigned int *i, int *src_ended, int *len)
{
	*i = 0;
	*src_ended = 0;
	*len = 0;
}

void	src_ended_check(int i, char *src, char *dest, int *src_ended)
{
	if (src[i] == '\0')
		*src_ended = 1;
	if (*src_ended)
		dest[i] = '\0';
}

unsigned int	get_str_len(char *src)
{
	unsigned int	len;

	len = 0;
	while (*src)
	{
		len++;
		src++;
	}
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				src_ended;
	int				len;

	init_variables(&i, &src_ended, &len);
	if (!size)
		return (get_str_len(src));
	if (src == 0)
		return (0);
	if (dest == 0)
		return (get_str_len(src));
	while (i < size - 1)
	{
		src_ended_check(i, src, dest, &src_ended);
		if (!src_ended)
		{
			dest[i] = src[i];
			len++;
		}
		i++;
	}
	if (!src_ended)
		dest[i] = '\0';
	return (get_str_len(src));
}
