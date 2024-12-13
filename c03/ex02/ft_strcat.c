/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:22:29 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/08 16:42:58 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*start;

	start = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (start);
}

int	main(void)
{
	char	*str;
	char	dest[50];

	str = " World!!!!";
	dest[0] = 'H';
	dest[1] = 'e';
	dest[2] = 'l';
	dest[3] = 'l';
	dest[4] = 'o';
	dest[5] = '\0';
	ft_strcat(dest, str);
	printf("%s\n", dest);
	return (0);
}
