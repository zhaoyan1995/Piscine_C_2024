/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:38:47 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/01 17:02:02 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	printf("The value of dest[0] = %c\n", *dest);
	printf("The value of dest[0] = %c\n", dest[0]);
	printf("The value of dest[1] = %c\n", *(dest + 1));
	printf("The value of dest[1] = %c\n", dest[1]);
	printf("The whole value of array dest = %s\n", dest);
	printf("The adress of dest = %p\n", dest);
	return (dest);
}

int	main(void)
{
	char	dest_array[100];
	char	*src_array;

	src_array = "Miao miao miao miao!!";
	printf("%s \n", ft_strcpy(dest_array, src_array));
	return (0);
}
