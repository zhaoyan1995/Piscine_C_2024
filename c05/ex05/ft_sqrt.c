/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:15:18 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/13 15:27:01 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	result = 1;
	while (result * result < nb)
		result ++;
	if (result * result == nb)
		return (result);
	else
		return (0);
}

int	main(void)
{
	int	nb;

	nb = 36;
	printf("ft_sqrt = %d\n", ft_sqrt(nb));
	return (0);
}
