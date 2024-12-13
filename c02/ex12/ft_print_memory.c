/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 02:07:52 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/06 18:33:41 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	decimal_to_hexadecimal(unsigned long decimal)
{
	char	hexadecimal;

	if (decimal == 0)
	{
		return ;
	}
	decimal_to_hexadecimal(decimal / 16);
	if (decimal % 16 < 10)
	{
		hexadecimal = decimal % 16 + '0';
		write(1, &hexadecimal, 1);
	}
	else
	{
		hexadecimal = (decimal % 16 - 10) + 'a';
		write(1, &hexadecimal, 1);
	}
}

void	ft_print_adress(unsigned long decimal)
{
	int				number_non_zero;
	int				number_zero;
	unsigned long	decimal2;

	decimal2 = decimal;
	number_non_zero = 0;
	while (decimal2 != 0)
	{
		decimal2 = decimal2 / 16;
		number_non_zero++;
	}
	number_zero = 16 - number_non_zero;
	while (number_zero > 0)
	{
		write(1, "0", 1);
		number_zero--;
	}
	decimal_to_hexadecimal(decimal);
	write(1, ": ", 2);
}

void	print_hex_str(unsigned char *str, unsigned int count, unsigned int size)
{
	int	i;

	i = 0;
	while (i < 16 && str[i] != '\0' && count < size)
	{
		if (str[i] < 32)
			write(1, "0", 1);
		decimal_to_hexadecimal(str[i]);
		if (i % 2 != 0)
			write(1, " ", 1);
		i++;
		count++;
	}
	if (i < 16)
		write(1, "     ", 5);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			*str;	
	int				i;
	unsigned int	count;	

	count = 0;
	while (count < size)
	{
		ft_print_adress((unsigned long)(addr));
		print_hex_str((unsigned char *)addr, count, size);
		i = 0;
		str = (char *)addr;
		while (i < 16 && str[i] != '\0' && count < size)
		{
			if (str[i] < 32)
				write(1, ".", 1);
			else
				write(1, &str[i], 1);
			i++;
			count++;
		}
		write(1, "\n", 1);
		addr += 16;
	}
	return (addr);
}

int	main(void)
{
	char	*str;

	str = "Salut les amies,vous savez important de brosser les dents tous les jour!";
	ft_print_memory(str, 30);
	return (0);
}
