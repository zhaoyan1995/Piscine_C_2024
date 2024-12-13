/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:05:40 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/01 21:13:39 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= 'a' && *str <= 'z'))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int	main(void)
{
	char	*string1;
	char	*string2;
	char	*string3;

	string1 = "Hello";
	printf("The string1 is \"%s\".\n", string1);
	printf("The result of string1 is %d.\n", ft_str_is_lowercase(string1));
	string2 = "";
	printf("The string2 is \"%s\".\n", string2);
	printf("The result of string2 is %d.\n", ft_str_is_lowercase(string2));
	string3 = "hello";
	printf("The string3 is \"%s\".\n", string3);
	printf("The result of string3 is %d.\n", ft_str_is_lowercase(string3));
	return (0);
}
