/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:27:57 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/23 23:57:48 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "/home/yan/Code_C/c08/ex00/ft.h"

void	ft_swap(int *a, int *b);

void	ft_swap(int *a, int *b)
{
	int	x;

	x = *b;
	*b = *a;
	*a = x;
}

/*int	main(void)
{
	int	a1;
	int	b1;

	a1 = 43;
	b1 = 26;
	printf("Before using the function swap a=%d b=%d\n", a1, b1);
	ft_swap(&a1, &b1);
	printf("After using the function swap a=%d b=%d\n", a1, b1);
	return (0);
}*/
