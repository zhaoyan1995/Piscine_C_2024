/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:42:25 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/02 00:07:05 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str = *str + 32;
		}
		str++;
		i++;
	}
	return (str - i);
}

//You CAN'T use char *string if you want to modify this string 
//by using the function above, 
//if so it will crash the program, 
//char *string can only define a readable string
//but you can not modify the content of this string after.
int	main(void)
{
	char	string1[7];

	string1[0] = 'A';
	string1[1] = 'E';
	string1[2] = 'L';
	string1[3] = 'l';
	string1[4] = 'O';
	string1[5] = '4';
	string1[6] = '\0';
	printf("The string1 is \"%s\".\n", string1);
	printf("After using function, it is \"%s\".\n", ft_strlowcase(string1));
	return (0);
}
