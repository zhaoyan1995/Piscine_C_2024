/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:36:20 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/11/28 21:31:47 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

void	ft_print_comb(void)
{
	int		n;
	char	buffer[3];

	n = 12;
	while (n < 999)
	{
		buffer[0] = n / 100 + '0';
		buffer[1] = n / 10 % 10 + '0';
		buffer[2] = n % 10 + '0';
		if (buffer[0] < buffer[1] && buffer[1] < buffer[2])
		{
			write(1, &buffer[0], 1);
			write(1, &buffer[1], 1);
			write(1, &buffer[2], 1);
			if (n != 789)
			{
				write(1, ", ", 2);
			}
		}
		n++;
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
