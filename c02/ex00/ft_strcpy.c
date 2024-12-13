/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:38:47 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/03 15:28:26 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* strcpy function can only be applied
 * when the size of *dest >= size of *src 
 * if not, it will display stack smashing detected error*/

/* When dest copied all the characters from src,
 * it will not copy the last element of src '\0'
 * so at the end, we need to add '\0' for dest */

char	*ft_strcpy(char *dest, char *src);

char	*ft_strcpy(char *dest, char *src)
{
	int		i;
	char	*start;

	i = 0;
	start = dest;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	printf("The value of dest[0] = %c\n", *(dest - i));
	printf("The value of dest[1] = %c\n", *(dest - i + 1));
	printf("The adress of dest = %p\n", dest - i);
	*dest = '\0';
	printf("The whole value of array dest = %s\n", dest - i);
	return (start);
}

int	main(void)
{
	char	dest_array[16];
	char	*src_array;

	src_array = "Hello Coucou";
	ft_strcpy(dest_array, src_array);
	printf("dest_array is \"%s\"\n", dest_array);
	return (0);
}
