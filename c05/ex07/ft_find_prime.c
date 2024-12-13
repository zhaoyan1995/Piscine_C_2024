/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_prime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:28:06 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/13 17:03:15 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	prime_verification(int nb, int factor, int nb_factor)
{
	if (factor == nb)
	{
		nb_factor++;
		return (nb_factor);
	}
	if (nb % factor == 0)
		return (prime_verification(nb, factor + 1, nb_factor + 1));
	else
		return (prime_verification(nb, factor + 1, nb_factor));
}

int	ft_find_next_prime(int nb)
{
	int	nb_factor;

	if (nb <= 1)
		nb = 2;
	while (1)
	{
		nb_factor = prime_verification(nb, 1, 0);
		if (nb_factor == 2)
			break ;
		nb++;
	}
	return (nb);
}

int	main(void)
{
	printf("%d\n", ft_find_next_prime(42));
	return (0);
}
