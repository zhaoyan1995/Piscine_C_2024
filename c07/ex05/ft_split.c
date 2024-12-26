/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:16:15 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/23 00:44:19 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

//In two cases ft_strlen_charset == 0 
//1st, when the str start with charset
//2st, when the str is an empty string.
//when str match the charset we return i immediately
//i == memory_split for each splited string 
//if a string can not mmet a charset, 
//it will return the total length of this string (until '\0');
int	ft_strlen_charset(char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (charset[j] != '\0' && str[i + j] != '\0'
			&& charset[j] == str[i + j])
			j++;
		if (charset[j] == '\0')
			return (i);
		i++;
	}
	return (i);
}

///In two cases ft_strlen_charset == 0 
//1st, when the str start with charset
//2st, when the str is an empty string.
//So while (ft_strlen_charset(str, charset) == 0) is not enough.
//we have to add *str != '\0' to avoid the str go forward beyond '\0'.
//and break the external while loop immediately to return the nb_strings value!
int	count_strings(char *str, char *charset)
{
	int	nb_strings;

	nb_strings = 0;
	while (*str != '\0')
	{
		while (ft_strlen_charset(str, charset) == 0 && *str != '\0')
			str += ft_strlen(charset);
		if (*(str) == '\0')
			break ;
		nb_strings++;
		str = str + ft_strlen_charset(str, charset);
	}
	return (nb_strings);
}

char	**ft_split(char *str, char *charset)
{
	int		num_strings;
	int		memory_split;
	int		i;
	int		j;
	char	**result;

	num_strings = count_strings(str, charset);
	result = (char **)malloc((num_strings + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < num_strings && *str != '\0')
	{
		j = 0;
		while (ft_strlen_charset(str, charset) == 0 && *str != '\0')
			str += ft_strlen(charset);
		memory_split = ft_strlen_charset(str, charset);
		result[i] = (char *)malloc(memory_split + 1);
		while (j < memory_split && *str != '\0')
			result[i][j++] = *(str++);
		result[i][j] = '\0';
		i++;
	}
	result[i] = 0;
	return (result);
}

int	main(void)
{
	char	*str;
	char	*charset;
	char	**result;
	int		i;

	str = "*$*$Hello*$*$World*$Comment*$tu*$vas?";
	printf("str = \"%s\"\n", str);
	charset = "*$";
	printf("number of strings is %d\n", count_strings(str, charset));
	result = ft_split(str, charset);
	i = 0;
	while (result[i] != NULL)
	{
		printf("result[%d] = %s\n", i, result[i]);
		i++;
	}
	printf("result[%d] = %s\n", i, result[i]);
	char	*str2 ="*$zefdsfsdf";
	printf("ft_strlen_charset(str2, charset) = %d\n", ft_strlen_charset(str2, charset));
	char	*str3 = "";
	printf("ft_strlen_charset(str3, charset) = %d\n", ft_strlen_charset(str3, charset));	
	free(result);
	return (0);
}
