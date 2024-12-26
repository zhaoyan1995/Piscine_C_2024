/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:57:04 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/20 23:52:10 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_sign_check_nbr(char *nbr, int *sign)
{
	while (*nbr == ' ' || *nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			*sign = -(*sign);
		nbr++;
	}
	return (nbr);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (-1);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (-1);
		i++;
	}
	if (i < 2)
		return (-1);
	return (i);
}

char	*ft_convert_zero(char *num_to)
{
	num_to = (char *)malloc(2);
	if (num_to == NULL)
		return (NULL);
	num_to[0] = '0';
	num_to[1] = '\0';
	return (num_to);
}

int	find(char *c, char *base_from)
{
	int	i;

	i = 0;
	while (base_from[i] != '\0')
	{
		if (*c == base_from[i])
			return (i);
		i++;
	}
	return (-1);
}
