/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_to_hexadecimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 02:00:42 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/06 02:00:59 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void decimal_to_hexadecimal(unsigned long decimal)
{
	char hexadecimal;	
	
	if (decimal == 0  )
	{
		return ;
	}
	decimal_to_hexadecimal(decimal / 16);
	if (decimal % 16 < 10)
	{
		hexadecimal = decimal % 16 + '0';
		write(1, &hexadecimal, 1);	
	}else if (decimal % 16 >= 10)
	{
		hexadecimal = (decimal % 16 - 10)+ '0' + 49;
		write(1, &hexadecimal, 1);
	}
}

int main (void)
{
	unsigned long decimal;

	decimal = 4294967295ULL;
	decimal_to_hexadecimal(decimal);
	return (0);
}
