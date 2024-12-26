/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:53:42 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/19 14:59:46 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

int	memory_for_result(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len_total;
	int	len_sep;

	len_total = 0;
	len_sep = ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			j++;
			len_total++;
		}
		i++;
		if (i != size - 1)
			len_total = len_total + len_sep;
	}
	return (len_total);
}

void	copy_strs(char *result, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			result[k++] = strs[i][j++];
		j = 0;
		while (i != size - 1 && j < ft_strlen(sep))
			result[k++] = sep[j++];
		i++;
	}
	result[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	char	*empty_str;	

	if (size == 0)
	{
		empty_str = (char *)malloc(1);
		if (empty_str == NULL)
			return (NULL);
		empty_str[0] = '\0';
		return (empty_str);
	}
	result = (char *)malloc((memory_for_result(size, strs, sep) + 1));
	if (result == NULL)
		return (NULL);
	copy_strs(result, strs, sep, size);
	return (result);
}

int	main(void)
{
	char	*strs[4];
	char	*sep;
	char	*result;
	int		size;

	strs[0] = "Hello";
	strs[1] = "World";
	strs[2] = "Lilou";
	strs[3] = "Zoe";
	sep = "--";
	size = sizeof(strs) / sizeof(*strs);
	result = ft_strjoin(size, strs, sep);
	if (result != NULL)
	{
		printf("%s\n", result);
		free(result);
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	return (0);
}
