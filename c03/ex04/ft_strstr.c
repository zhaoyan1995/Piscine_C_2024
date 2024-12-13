/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:39:05 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/08 16:23:58 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*not_found;

	i = 0;
	j = 0;
	not_found = "";
	if (to_find[j] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && to_find[j] != '\0')
		{
			if (str[i + j] != to_find[j])
				break ;
			j++;
		}
		if (to_find[j] == '\0')
			return (str + i);
		i++;
	}
	return (not_found);
}

int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "HelloWorld!!!!World";
	str2 = "World";
	printf("%s", ft_strstr(str1, str2));
	return (0);
}
