/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:28:09 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/13 16:26:04 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	prime_helper(int nb, int factor, int nb_factor)
{
	if (factor == nb)
	{
		nb_factor++;
		if (nb_factor == 2)
			return (1);
		else
			return (0);
	}
	if (nb % factor == 0)
		return (prime_helper(nb, factor + 1, nb_factor + 1));
	else
		return (prime_helper(nb, factor + 1, nb_factor));
}

int	ft_is_prime(int nb)
{
	if (nb <= 1)
		return (0);
	return (prime_helper(nb, 1, 0));
}

int	main(void)
{
	printf("5 %d\n", ft_is_prime(5));
	return (0);
}
