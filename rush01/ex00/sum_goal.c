/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_goal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:27:04 by jnenczak          #+#    #+#             */
/*   Updated: 2023/10/01 14:27:06 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_sum_goal(int border_len)
{
	int	sum;
	int	border;

	sum = 0;
	border = border_len - 2;
	while (border > 0)
	{
		sum += border;
		border--;
	}
	return (sum);
}
