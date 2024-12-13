/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:15:08 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/01 16:57:15 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int	tab[5];
	int	size;
	int	i;

	tab[0] = 45;
	tab[1] = 1;
	tab[2] = 35;
	tab[3] = 28;
	tab[4] = 34;
	i = 0;
	size = sizeof(tab) / sizeof(tab[0]);
	while (i <= size - 1)
	{
		printf("tab[%d]=%d\n", i, tab[i]);
		i++;
	}
	ft_sort_int_tab(tab, size);
	printf("bubble\n");
	i = 0;
	while (i <= size - 1)
	{
		printf("tab[%d]=%d\n", i, tab[i]);
		i++;
	}
	return (0);
}
