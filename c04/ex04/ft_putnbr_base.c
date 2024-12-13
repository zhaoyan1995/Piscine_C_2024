/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:01:33 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/11 21:02:28 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr_base(int nbr, char *base);

int	measure_length(char *base)
{
	int	i;

	i = 0;
	while (*base != '\0')
	{
		i++;
		base++;
	}
	return (i);
}

void	if_min_int(int nbr, char *base, int base_length)
{
	write(1, "-", 1);
	ft_putnbr_base(-(nbr / base_length), base);
	write(1, &base[-(nbr % base_length)], 1);
}

int	verification_base(char *base)
{
	int	result;
	int	i;
	int	j;

	result = 1;
	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[j] == 43 || base[j] == 45)
				return (result);
			j++;
		}
		if (base[i] == 43 || base[i] == 45)
			return (result);
		i++;
	}
	if (i == 0 || i == 1)
		return (result);
	result = 0;
	return (result);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_length;	

	base_length = measure_length(base);
	if (verification_base(base) != 0)
		return ;
	if (nbr == 0)
	{
		write(1, &base[nbr], 1);
		return ;
	}
	if (nbr == -2147483648)
	{
		if_min_int(nbr, base, base_length);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr / base_length != 0)
		ft_putnbr_base(nbr / base_length, base);
	write(1, &base[nbr % base_length], 1);
}

int	ft_atoi(char *str)
{
	int	number;
	int	sign;

	number = 0;
	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		str++;
	}
	while (*str != '\0')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	number = number * sign;
	return (number);
}

int	main(int argc, char *argv[])
{
	int		number;	
	char	*base;

	if (argc != 3)
	{
		write(1, "please enter the number and the base.\n", 39);
		return (1);
	}
	number = ft_atoi(argv[1]);
	base = argv[2];
	ft_putnbr_base(number, base);
	return (0);
}
