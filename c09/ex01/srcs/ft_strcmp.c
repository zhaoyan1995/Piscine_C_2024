/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:54:32 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/27 16:24:17 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	result;

	result = 0;
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			result = (int)(*s1 - *s2);
			break ;
		}
		s1++;
		s2++;
	}
	return (result);
}

/*int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "abc";
	str2 = "abd";
	printf("%d\n", ft_strcmp(str1, str2));
	return (0);
}*/
