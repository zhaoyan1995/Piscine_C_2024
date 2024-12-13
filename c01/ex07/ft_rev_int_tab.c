/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:58:51 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/01 15:35:32 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i <= (size - 1) / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}

int	main(void)
{
	int	tab[4];
	int	size;

	tab[0] = 32;
	tab[1] = 45;
	tab[2] = 12;
	tab[3] = 78;
	size = sizeof(tab) / sizeof(tab[0]);
	printf("before reversing:\n");
	printf("tab[0] = %d, tab[1] = %d, ", tab[0], tab[1]);
	printf("tab[2] = %d, tab[3] = %d\n", tab[2], tab[3]);
	ft_rev_int_tab(tab, size);
	printf("after reversing:\n");
	printf("tab[0] = %d, tab[1] = %d, ", tab[0], tab[1]);
	printf("tab[2] = %d, tab[3] = %d\n", tab[2], tab[3]);
	return (0);
}
