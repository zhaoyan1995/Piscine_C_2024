/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:39:38 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/11/29 20:42:19 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	a1;
	int	b1;

	a1 = *a;
	b1 = *b;
	*a = a1 / b1;
	*b = a1 % b1;
}

int	main(void)
{
	int	a;
	int	b;

	a = 21;
	b = 5;
	ft_ultimate_div_mod(&a, &b);
	printf("a=%d b=%d\n", a, b);
	return (0);
}
