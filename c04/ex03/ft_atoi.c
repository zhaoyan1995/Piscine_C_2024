/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:46:49 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/09 21:25:06 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//ft_pow for x^y
int	ft_pow(int x, int y)
{
	if (y == 0)
	{
		return (1);
	}
	return (x * ft_pow(x, y - 1));
}

//ft_count_nb_sign counts the nb_sign of "+" "-" and " ".
int	ft_count_nb_sign(char *str)
{
	int	nb_sign;

	nb_sign = 0;
	while (*str == 45 || *str == 43 || *str == 32)
	{
		nb_sign++;
		str++;
	}
	return (nb_sign);
}

//count_negative counts the number of "-".
int	count_negative(char *str)
{
	int	i;	
	int	nb_negative;

	i = 0;
	nb_negative = 0;
	while (str[i] == 45 || str[i] == 43 || str[i] == 32)
	{
		if (str[i] == 45)
		{
			nb_negative++;
		}
		i++;
	}
	return (nb_negative);
}

// i is the number of number before it meets other than a character as number like "a" "?" or "-" or "+".
int	ft_atoi(char *str)
{
	int	number;
	int	i;
	int	nb_sign;
	int	nb_negative;

	nb_sign = ft_count_nb_sign(str);
	number = 0;
	nb_negative = count_negative(str);
	str += nb_sign;
	i = 0;
	while (str[i] >= 48 && str[i] <= 57 && str[i] != 0)
		i++;
	while (*str >= 48 && *str <= 57 && *str != '\0')
	{
		number = (*str - '0') * ft_pow(10, (i - 1)) + number;
		str++;
		i--;
	}
	if (nb_negative % 2 == 0)
		return (number);
	else
		return (-number);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		printf("%d\n", ft_atoi(argv[i]));
		i++;
	}
	return (0);
}
