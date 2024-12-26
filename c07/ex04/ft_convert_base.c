/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:07:01 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/20 23:54:52 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_sign_check_nbr(char *nbr, int *sign);
char	*ft_convert_zero(char *num_to);
int		check_base(char *base);
int		find(char *c, char *base_from);

int	ft_atoi_base(char *nbr_from, char *base_from, int len_from)
{
	int	num_dec;

	num_dec = 0;
	while (*nbr_from != '\0')
	{
		if (find(nbr_from, base_from) < 0)
			return (num_dec);
		num_dec = num_dec * len_from + find(nbr_from, base_from) % len_from;
		nbr_from++;
	}
	return (num_dec);
}

int	measure_memory(char *base_to, int num_dec, int sign)
{
	int	memory_size;

	memory_size = 0;
	while (num_dec != 0)
	{
		num_dec = num_dec / check_base(base_to);
		memory_size++;
	}
	if (sign < 0)
		memory_size++;
	return (memory_size);
}

void	ft_put_nbr(char *base_to, char *num_to, int num_dec, int sign)
{
	int	len_to;	
	int	memory_size;

	len_to = check_base(base_to);
	memory_size = measure_memory(base_to, num_dec, sign);
	printf("memory_size is %d\n", memory_size);	
	num_to[memory_size] = '\0';
	memory_size--;
	while (memory_size > 0)
	{
		num_to[memory_size] = base_to[num_dec % len_to];
		num_dec = num_dec / len_to;
		memory_size--;
	}
	if (sign < 0)
		num_to[memory_size] = '-';
	else
		num_to[memory_size] = base_to[num_dec % len_to];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		sign;	
	int		memory_size;
	int		num_dec;	
	char	*num_to;

	sign = 1;
	nbr = ft_sign_check_nbr(nbr, &sign);
	if (check_base(base_from) < 0 || check_base(base_to) < 0)
		return (NULL);
	if (*nbr == '0')
	{
		num_to = NULL;
		return (ft_convert_zero(num_to));
	}
	num_dec = ft_atoi_base(nbr, base_from, check_base(base_from));
	if (num_dec == 0)
		return (NULL);
	memory_size = measure_memory(base_to, num_dec, sign);
	num_to = (char *)malloc(memory_size + 1);
	if (num_to == NULL)
		return (NULL);
	ft_put_nbr(base_to, num_to, num_dec, sign);
	return (num_to);
}

int	main(void)
{
	char	*nbr;
	char	*base_from;
	char	*base_to;
	char	*nbr_to;

	nbr = "-- -+207a cEf";
	base_from = "0123456789";
	base_to = "01";
	nbr_to = ft_convert_base(nbr, base_from, base_to);
	if (nbr_to != NULL)
		printf("result is %s\n", nbr_to);
	free(nbr_to);
	return (0);
}
