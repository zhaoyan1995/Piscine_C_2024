/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:54:08 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/16 16:47:15 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

//Print 1 solution (the value of array that contains 10 digits) by line
void	print_solution(int *array)
{
	int		i;	
	char	y;	

	i = 0;
	while (i < 10)
	{
		y = array[i] + '0';
		write(1, &y, 1);
		i++;
	}
	write(1, "\n", 1);
}

//Filte the invalid array even before the 10 digits has been generated!
//if two digits have the same value => non-valided 
//or the abs value of (queen_i - queen_current) == 
//abs value of (array[queen_i] - line_num_queen_current) => non_valided
int	filter(int *array, int queen_current, int line_num_queen_current)
{
	int	queen_i;
	int	x;	
	int	y;

	queen_i = 0;
	while (queen_i < queen_current)
	{
		x = array[queen_i] - line_num_queen_current;
		y = queen_i - queen_current;
		if (x < 0)
			x = -x;
		if (y < 0)
			y = -y;
		if (array[queen_i] == line_num_queen_current || x == y)
			return (0);
		queen_i++;
	}
	return (1);
}

//Generate_array is to generate the solution line by line 
//and count the number of solution 
//using (*nb_solution) ++ to update the value of *nb_solution 
//instead of using *nb_solution++
//(just move on to the next adress of nb_solution pointer, if not the value is always "0".
void	generate_array(int array[], int queen_current, int *nb_solution)
{
	int	line_num_queen_current;
	int	valid;

	if (queen_current == 10)
	{
		print_solution(array);
		(*nb_solution)++;
		return ;
	}
	line_num_queen_current = 0;
	while (line_num_queen_current < 10)
	{
		valid = filter(array, queen_current, line_num_queen_current);
		if (valid == 1)
		{
			array[queen_current] = line_num_queen_current;
			generate_array(array, queen_current + 1, nb_solution);
		}
		line_num_queen_current++;
	}
}

//The principal function to kick off the calculation
//We start from queen_num = 0
//and nb_solution = 0, variable nb_solution = *nb_solution
//in order to update the value of nb_solution
//and return the real nb_solution at the end
int	ft_ten_queens_puzzle(void)
{
	int	array[10];
	int	queen_num;
	int	nb_solution;	

	queen_num = 0;
	nb_solution = 0;
	generate_array(array, queen_num, &nb_solution);
	return (nb_solution);
}

int	main(void)
{
	printf("the number of solution is %d\n", ft_ten_queens_puzzle());
	return (0);
}
