/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:28:26 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/11/29 18:32:44 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ft(int *nbr);

void	ft_ft(int *nbr)
{
	*nbr = 42;
	return ;
}

int	main(void)
{
	int		number;
	int		*nbr;

	number = 2;
	nbr = &number;
	ft_ft(nbr);
	printf("%d\n", number);
	return (0);
}
