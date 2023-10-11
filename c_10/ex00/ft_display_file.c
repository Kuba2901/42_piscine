/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 23:57:35 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/11 23:57:48 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	str--;
	while (*(++str))
		write(1, str, 1);
}

void	display_file(char *file_name)
{
	int		file;
	char	c;

	file = open(file_name, O_RDONLY);
	if (file == -1)
	{
		ft_putstr("Cannot read file.\n");
		return ;
	}
	while (read(file, &c, 1))
		write(1, &c, 1);
	close(file);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_putstr("File name missing.\n");
		return (0);
	}
	else if (ac > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (0);
	}
	display_file(av[1]);
	return (0);
}
