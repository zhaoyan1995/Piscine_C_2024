/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:24:18 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/16 16:58:08 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 

//Print each char from str[] from 0 to i - 1
void	ft_print_str(char str[])
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

//Sort all the strings transfered from *argv[] from 0 to argc - 1
void	sort_string(char *dest[], int size)
{
	int		i;
	int		j;
	char	*tempo;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (*dest[i] > *dest[j])
			{
				tempo = dest[j];
				dest[j] = dest[i];
				dest[i] = tempo;
			}
			j++;
		}
		i++;
	}
}

//Create the pointer pointer **dest in order to transfer all
//the value from *argv[] to **dest to sort all the strings in order
int	main(int argc, char *argv[])
{
	int		i;
	char	**dest;

	dest = argv;
	if (argc > 1)
		sort_string(dest, argc);
	i = 1;
	while (i < argc)
	{
		ft_print_str(dest[i]);
		i++;
	}
	return (0);
}
