/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:22:18 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/29 16:18:45 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strlen_charset(char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (charset[j] == str[i + j] && charset[j] != '\0'
			&& str[i + j] != '\0')
			j++;
		if (j == ft_strlen(charset))
			return (i);
		i++;
	}
	return (i);
}

int	ft_count_strings(char *str, char *charset)
{
	int	num_strings;

	num_strings = 0;
	while (*str != '\0')
	{
		while (ft_strlen_charset(str, charset) == 0 && *str != '\0')
			str += ft_strlen(charset);
		if (*str != '\0')
		{
			num_strings++;
			str += ft_strlen_charset(str, charset);
		}
	}
	return (num_strings);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		num_strings;
	int		len_string;
	int		i;
	int		j;

	num_strings = ft_count_strings(str, charset);
	result = (char **)malloc(sizeof(char *) * (num_strings + 1));
	i = 0;
	while (*str != '\0')
	{
		while (ft_strlen_charset(str, charset) == 0 && *str != '\0')
			str += ft_strlen(charset);
		if (*str == '\0')
			break ;
		len_string = ft_strlen_charset(str, charset);
		result[i] = (char *)malloc(len_string + 1);
		j = 0;
		while (j < len_string && *str != '\0')
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

	str = "EZTFE$*RFZEF$*";
	charset = "$*";
	i = 0;
	result = ft_split(str, charset);
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		free(result[i]);
		i++;
	}
	printf("final result[i] = %s\n", result[i]);
	free (result);
	return (0);
}
