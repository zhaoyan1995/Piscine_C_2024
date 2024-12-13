/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:36:54 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/09 00:07:01 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//i = length of string dest
//j = length of string src
//k is to make sure if we have enough space to introduce element from src to dest.
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	if (size <= i)
		return (size + j);
	while (k < (size - i - 1) && src[k] != '\0')
	{
		dest[i + k] = src[k];
		k++;
	}
	dest[i + k] = '\0';
	return (i + j);
}

int	main(void)
{
	char	*source;
	char	dest[30] = "ABCD";
	int	size;
	
	size = 10;
	source = "EFGHI";	
	printf("size = %d ",size);
	printf("return value of strlcat is %d\n", ft_strlcat(dest, source, size));
	printf("dest = %s\n", dest);
	return (0);
}
