/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:42:06 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/17 23:59:30 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;	
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		length_src;
	char	*dest;

	if (src == NULL)
		return (NULL);
	length_src = ft_strlen(src);
	dest = (char *)malloc((length_src + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(void)
{
	char	str[100] = "Hello Lilou";
	char	*dest;

	dest = ft_strdup(str);
	if (dest == NULL)
	{
		printf("allocation memory failed!");
		return (1);
	}
	printf("%s\n", dest);
	free(dest);
	return (0);
}
