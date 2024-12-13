/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:28:09 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/13 16:31:13 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	nb_factor;	
	int	factor;

	factor = 1;
	nb_factor = 0;
	if (nb <= 1)
		return (0);
	while (factor <= nb)
	{
		if (nb % factor == 0)
			nb_factor++;
		factor++;
	}
	if (nb_factor == 2)
		return (1);
	return (0);
}

int	main(void)
{
	printf("0 %d\n", ft_is_prime(0));
	printf("1 %d\n", ft_is_prime(1));
	printf("2 %d\n", ft_is_prime(2));
	printf("23 %d\n", ft_is_prime(23));
	return (0);
}
