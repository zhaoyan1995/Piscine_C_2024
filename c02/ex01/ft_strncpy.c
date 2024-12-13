/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:49:06 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/03 15:24:04 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// strncpy copies up to n characters from src to dest.
// If size_src < n : 
// The length of the source string (size_src) is less than n,
// it will pad(or fill out) the remaining space in dest with '\0' 
// until n characters are filled.
// If size_src >= n : 
// The length of the source string (size_src) is greater than or equal to n,
// it will NOT ADD '\0' at the end of dest.
// ATTENTION : 
// n should always be <= size of dest, if not it will crash the program.

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	size_src;
	char			*start;

	size_src = 0;
	start = dest;
	while (size_src < n && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		size_src++;
	}
	printf("*(dest-size_src)=%c\n", *(dest - size_src));
	printf("size_src=%d\n", size_src);
	printf("n=%d\n", n);
	while (size_src < n)
	{
		*dest = '\0';
		dest++;
		size_src++;
	}
	return (start);
}

int	main(void)
{
	char	dest[5];
	char	*src;

	src = "Haru haru";
	ft_strncpy(dest, src, 3);
	printf("%s\n", dest);
	return (0);
}
