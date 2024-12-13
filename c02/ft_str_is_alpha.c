/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:05:40 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/01 19:40:05 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	num;
	int	result;
	int	i;

	i = 0;
	while (*str != '\0')
	{
		num = (int)*str;
		if (!((num >= 65 && num <= 90) || (num >= 97 && num <= 122)))
		{
			i++;
		}
		str++;
	}
	if (i == 0)
	{
		result = 1;
	}
	else
	{
		result = 0;
	}
	return (result);
}

int	main(void)
{
	char	*string1;
	char	*string2;
	char	*string3;

	string1 = "eqrfzraée_çéd";
	printf("The string1 is \"%s\".\n", string1);
	printf("The result of string1 is %d.\n", ft_str_is_alpha(string1));
	string2 = "";
	printf("The string2 is \"%s\".\n", string2);
	printf("The result of string2 is %d.\n", ft_str_is_alpha(string2));
	string3 = "Hello";
	printf("The string3 is \"%s\".\n", string3);
	printf("The result of string3 is %d.\n", ft_str_is_alpha(string3));
	return (0);
}
