/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:42:18 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/11/29 11:58:21 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_print_comb(void)
{
	char	buffer[2];
	int		n1;
	int		n2;

	n1 = 0;
	while (n1 <= 99)
	{
		n2 = n1 + 1;
		while (n2 <= 99)
		{
			buffer[0] = n1 / 10 + '0';
			buffer[1] = n1 % 10 + '0';
			write(1, &buffer, 2);
			write(1, " ", 1);
			buffer[0] = n2 / 10 + '0';
			buffer[1] = n2 % 10 + '0';
			write(1, &buffer, 2);
			if (n1 != 98 || n2 != 99)
			{
				write(1, ", ", 2);
			}
			n2++;
		}
		n1++;
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
