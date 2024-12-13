/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:15:18 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/13 16:05:01 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	sqrt_helper(int nb, int result)
{
	if (result * result == nb)
		return (result);
	else if (result * result > nb)
		return (0);
	return (sqrt_helper(nb, result + 1));
}

int	ft_sqrt(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	return (sqrt_helper(nb, 1));
}

int	main(void)
{
	int	nb;

	nb = 6084;
	printf("ft_sqrt = %d\n", ft_sqrt(nb));
	return (0);
}
