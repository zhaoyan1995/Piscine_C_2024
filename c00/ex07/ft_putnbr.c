/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:01:32 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/11/29 18:25:58 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

void	ft_putnbr(int nb)
{
	char	digit;

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
		digit = nb % 10 + '0';
		write(1, &digit, 1);
	}
}

int	main(void)
{
	ft_putnbr(-40);
	return (0);
}
