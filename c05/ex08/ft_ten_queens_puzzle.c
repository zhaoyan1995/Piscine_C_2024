/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:54:08 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/13 21:46:35 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	generate_array()
{
		
}

int	ft_ten_queens_puzzle(void)
{	
	int	result;	
	int	start_number;
	int	start_number_ten;
	
	start_number = 1;	
	if (start_number == 0)
		write(1,"0", 1);	
	start_number_ten = 1 * 1000000000;

	result = generate_array(); 
	return (result);
}

int	main(void)
{
	printf("%d\n",ft_ten_queens_puzzle());	
	return (0);
}	
