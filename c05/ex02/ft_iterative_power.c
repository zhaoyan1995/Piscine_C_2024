/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:11:09 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/13 00:26:34 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 1;
	result = nb;
	while (i < power)
	{
		result = result * nb;
		i ++;
	}
	return (result);
}

int	main(void)
{
	int	nb;
	int	power;

	nb = 0;
	power = 0;
	printf("%d\n", ft_iterative_power(nb, power));
	return (0);
}
