/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:54:59 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/01 15:33:27 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (*str != '\0')
	{
		str++;
		n++;
	}
	return (n);
}

int	main(void)
{
	char	*str;
	int		i;

	str = "Hello world, Salut Lilou!\n";
	printf("%d\n", ft_strlen(str));
	i = strlen(str);
	printf("%d\n", i);
	return (0);
}
