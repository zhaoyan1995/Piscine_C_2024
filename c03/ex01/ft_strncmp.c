/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:35:05 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/06 21:10:46 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	result;

	result = 0;
	while (n > 0 && (*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 != *s2)
		{
			result = (int)(*s1 - *s2);
			break ;
		}
		s1++;
		s2++;
		n--;
	}
	return (result);
}

int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "pain au chocolate";
	str2 = "pain aux raisins";
	printf("%d\n", ft_strncmp(str1, str2, 7));
	printf("%d\n", ft_strncmp(str1, str2, 8));
	return (0);
}
