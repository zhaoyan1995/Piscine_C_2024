/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:37:26 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/02 19:01:26 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//If the string is a capital letter,
//then you need to transform it to lowercase letter.
void	upcase_lowcase(char *str)
{
	if (*str >= 'A' && *str <= 'Z')
	{
		*str += 32;
	}
}

//ptr is the pointer variable to 
//take the value of the beginning of the array *str
char	*ft_strcapitalize(char *str)
{
	char	*ptr;

	ptr = str;
	while (*str != '\0')
	{
		if (*(str - 1) >= 'A' && *(str - 1) <= 'Z')
			upcase_lowcase(str);
		else if (*(str - 1) >= '0' && *(str - 1) <= '9')
			upcase_lowcase(str);
		else if (*(str - 1) >= 'a' && *(str + 1) <= 'z')
			upcase_lowcase(str);
		else
		{
			if (*str >= 'a' && *str <= 'z')
				*str -= 32;
		}
		str++;
	}
	return (ptr);
}

//You CAN'T use char *string if you want to modify this string 
//by using the function above, 
//if so it will crash the program, 
//char *string can only define a readable string
//you can not modify the content of this string after.
//If you want to create a char *string and modify it after
//You can apply "strcpy(destination, source) function
//Make sure that the destination[] has sufficient space to copy 
//each element from *source!
int	main(void)
{
	char	*string1;
	char	dest[100];

	string1 = "salut, comment tu vas? 42MOTS quarante-deux; cinquante+et+un";
	strcpy(dest, string1);
	printf("The string1 is \"%s\".\n", dest);
	printf("After using function, it is \"%s\".\n", ft_strcapitalize(dest));
	return (0);
}
