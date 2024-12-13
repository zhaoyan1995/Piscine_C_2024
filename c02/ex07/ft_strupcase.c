/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:42:25 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/02 00:05:54 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str = *str - 32;
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

	string1[0] = 'a';
	string1[1] = 'e';
	string1[2] = 'L';
	string1[3] = 'l';
	string1[4] = 'o';
	string1[5] = 'z';
	string1[6] = '\0';
	printf("The string1 is \"%s\".\n", string1);
	printf("After using function, it is \"%s\".\n", ft_strupcase(string1));
	return (0);
}
