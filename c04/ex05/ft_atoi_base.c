/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:08:23 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/12 21:25:22 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// i = length of str if validation passed.
int	verification_str(char *str, char *base)
{
	int	i;
	int	j;
	int	base_length;
	int	result;

	base_length = 0;
	while (base[base_length] != '\0')
		base_length++;
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		result = 0;
		while (base[j] != '\0')
		{
			if (str[i] != base[j])
				result++;
			j++;
		}
		if (result == base_length)
			return (-1);
		i++;
	}
	return (i);
}

int	convert_base(char str, char *base)
{
	int	i;	

	i = 0;
	while (*base != '\0')
	{
		if (str == base[i])
			return (i);
		i++;
	}
	return (0);
}

// j = length of base if validation passed.
int	verification_base(char *base)
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
	if (i == 0 || i == 1)
		return (-1);
	return (j);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nbr;	
	int	base_length;
	int	str_length;
	int	i;
	int	sign;

	sign = 1;
	while (*str == '+' || *str == '-' || *str == ' ')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	if (verification_base(base) == -1 || verification_str(str, base) == -1)
		return (0);
	nbr = 0;
	base_length = verification_base(base);
	str_length = verification_str(str, base);
	i = -1;
	while (i++, str_length--, str_length >= 0)
	{
		nbr = convert_base(str[i], base) + nbr * base_length;
	}
	return (nbr * sign);
}

int	main(void)
{
	char	*str;
	char	*base;

	str = "   -111";
	base = "01";
	printf("result final = %d\n", ft_atoi_base(str, base));
	return (0);
}
