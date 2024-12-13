/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:19:47 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/09 00:11:05 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*start;

	start = dest;
	while (*dest != '\0')
		dest++;
	while (nb > 0 && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		nb--;
	}
	*dest = '\0';
	return (start);
}

int	main(void)
{
	char	*src;
	char	dest[50];

	src = "World!!!";
	dest[0] = 'H';
	dest[1] = 'e';
	dest[2] = 'l';
	dest[3] = 'l';
	dest[4] = 'o';
	dest[5] = '\0';
	ft_strncat(dest, src, 4);
	printf("%s\n", dest);
	return (0);
}
