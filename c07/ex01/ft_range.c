/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:31:13 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/18 12:26:48 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	range_size;
	int	i;	

	if (max <= min)
		return (NULL);
	range_size = max - min;
	range = (int *)malloc(range_size * sizeof(int));
	if (range == NULL)
		return (NULL);
	i = 0;
	while (i < range_size)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}

int	main(void)
{
	int	min;
	int	max;
	int	i;
	int	*range;

	min = 3;
	max = 6;
	i = 0;
	range = ft_range(min, max);
	if (range == NULL)
	{
		printf("failed to allocate the memory.\n");
		return (1);
	}
	while (i < (max - min))
	{
		printf("%d ", range[i]);
		i++;
	}
	free(range);
	return (0);
}
