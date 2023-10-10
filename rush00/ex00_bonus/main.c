/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:22:28 by fde-sist          #+#    #+#             */
/*   Updated: 2023/09/24 01:46:30 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int n, int m);
int		ft_atoi(char *str);

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	if (argc == 1)
		rush(0, 0);
	else if (argc == 2)
	{
		a = ft_atoi(argv[1]);
		rush(a, 0);
	}
	else
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[2]);
		rush(a, b);
	}
	return (0);
}
