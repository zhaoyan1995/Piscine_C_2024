/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:34:11 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/13 00:05:52 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	i = nb - 1;
	result = nb;
	while (i > 0)
	{
		result = result * i;
		i --;
	}
	return (result);
}

int	main(void)
{
	int	nb;

	nb = 5;
	printf("result = %d\n", ft_iterative_factorial(nb));
	return (0);
}
