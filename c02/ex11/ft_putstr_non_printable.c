/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:54:37 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/04 21:37:20 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	*decimal_to_hexadecimal(int digit, char *hex)
{
	char	digit_1;
	char	digit_2;

	digit_1 = digit / 16;
	digit_2 = digit % 16;
	hex[0] = digit_1 + 48;
	if (digit_2 < 10)
		hex [1] = digit_2 + 48;
	else if (digit_2 >= 10)
		hex [1] = (digit_2 - 10) + 49 + 48;
	if (digit >= 10)
	{
		hex[0] = digit_1 + 48;
	}
	hex[2] = '\0';
	return (0);
}

void	print_number(unsigned char non_printable)
{
	int		np_number;
	char	hex[3];

	np_number = (int)non_printable;
	decimal_to_hexadecimal(np_number, hex);
	write (1, hex, 3);
}

void	ft_put_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str < 32 || *str == 92 || *str == 34 || *str == 39)
		{
			write(1, "\\", 2);
			print_number(*str);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
	if (*str == '\0')
	{
		write(1, "\\", 2);
		print_number(*str);
		str++;
	}
}

int	main(void)
{
	char	*str;

	str = "Coucou\ntu vas bien?\0";
	ft_put_non_printable(str);
	return (0);
}
