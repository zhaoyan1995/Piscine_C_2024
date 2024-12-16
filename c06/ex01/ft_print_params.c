/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:39:37 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/14 21:21:13 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	if (argc > 0)
	{
		while (i < argc)
		{
			j = 0;
			str = argv[i];
			while (str[j] != '\0')
				j++;
			write(1, argv[i], j);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
