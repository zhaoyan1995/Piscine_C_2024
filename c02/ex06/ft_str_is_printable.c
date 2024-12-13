/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:22:40 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/01 21:24:46 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= 32))
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

	string1 = "ddd\t";
	printf("The string1 is \"%s\".\n", string1);
	printf("The result of string1 is %d.\n", ft_str_is_printable(string1));
	string2 = "";
	printf("The string2 is \"%s\".\n", string2);
	printf("The result of string2 is %d.\n", ft_str_is_printable(string2));
	string3 = "Hello";
	printf("The string3 is \"%s\".\n", string3);
	printf("The result of string3 is %d.\n", ft_str_is_printable(string3));
	return (0);
}
