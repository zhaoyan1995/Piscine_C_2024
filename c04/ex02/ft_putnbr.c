/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:11:59 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/09 16:08:20 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	number;

	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			write(1, "2", 1);
			nb = nb % 1000000000;
		}
		ft_putnbr(-nb);
	}
	else
	{
		if (nb / 10 != 0)
			ft_putnbr(nb / 10);
		number = (nb % 10) + '0';
		write(1, &number, 1);
	}
}

int	main(void)
{
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	return (0);
}
