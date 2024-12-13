/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:20:38 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/03 22:44:20 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* strlcpy will copy (size-1) characters from src to dest.
 * if dest_size > 0, the end of dest is always '\0' 
 * The 1st while loop must have 3 conditions
 *
 * size (dest size) > 1 is to avoid the overflow issue
 * if size (dest size) == 0 , without this condition (size <1) 
 * the program will try to fill the dest with src but size (dest size) == 0
 *
 * size_source < size -1 is for the situation that
 * size_source > dest size, we only copy the size-1 characters
 * the last place of dest is '\0'
 *
 * src[size_source] != '\0' is for the situation that
 * size of source < dest size, we can copy all the characters from src to dest*/

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	size_source;

	size_source = 0;
	while (size > 1 && size_source < size - 1 && src[size_source] != '\0')
	{
		dest[size_source] = src[size_source];
		size_source++;
	}
	if (size > 0)
	{
		dest[size_source] = '\0';
	}
	while (src[size_source] != '\0')
	{
		size_source++;
	}
	return (size_source);
}

int	main(void)
{
	char	*src1;
	char	dest1[5];
	char	*src2;
	char	dest2[10];
	char	*src3;
	char	dest3[0];
	char	*src4;
	char	dest4[5];

	src1 = "Hello, World!";
	printf("\nsrc1 = \"%s\"\n", src1);
	printf("size_dest1 (5) < size_src1 (13), the length of src1 is %d\n", ft_strlcpy(dest1, src1, sizeof(dest1)));
	printf("dest1 = \"%s\"\n\n", dest1);
	src2 = "Hi";
	printf("src2 = \"%s\"\n", src2);
	printf("size_dest2 (10) > size_src2 (2), the length of src2 is %d\n", ft_strlcpy(dest2, src2, sizeof(dest2)));
	printf("dest2 = \"%s\"\n\n", dest2);
	src3 = "Test";
	printf("src3 = \"%s\"\n", src3);
	printf("size_dest3 (0) < size_src3 (4), the length of src3 is %d\n", ft_strlcpy(dest3, src3, sizeof(dest3)));
	printf("dest3 = \"%s\"\n\n", dest3);
	src4 = "";
	printf("src4 = \"%s\"\n", src4);
	printf("size_dest4 (5) > size_src4 (0), the length of src4 is %d\n", ft_strlcpy(dest4, src4, sizeof(dest4)));
	printf("dest4 = \"%s\"\n\n", dest4);
	return (0);
}
