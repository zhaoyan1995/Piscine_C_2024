/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:26:22 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/25 18:36:35 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"
#include <stdio.h>

void	set_point(t_point *point)
{
	point -> x = 42;
	point -> y = 21;
}

int	main(void)
{
	t_point	point;

	set_point(&point);
	printf("x = %d, y = %d\n", point.x, point.y);
	return (0);
}
