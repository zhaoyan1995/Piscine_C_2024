/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:42:48 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/11/29 18:05:09 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

void	generate_digit(int array[], int index, int size_of_array, int digit)
{
	int		i;
	char	number;

	if (index == size_of_array)
	{
		i = 0;
		while (i < size_of_array)
		{
			number = array[i] + '0';
			write(1, &number, 1);
			i++;
		}
		if (array[0] != (10 - size_of_array))
		{
			write(1, ", ", 2);
		}
		return ;
	}
	while (digit <= 9)
	{
		array[index] = digit;
		generate_digit(array, index + 1, size_of_array, digit + 1);
		digit++;
	}
}

void	ft_print_combn(int n)
{
	int		arr[9];
	int		length;
	char	str[];

	if (n > 0 && n < 10)
	{
		generate_digit(arr, 0, n, 0);
	}
	else
	{
		str[] = "Error, you need to print a number between 1 and 9.";
		length = strlen(str);
		write(1, &str, length);
	}
}

int	main(void)
{
	ft_print_combn(4);
	return (0);
}
