/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:28:27 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/01/04 21:58:24 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_tail.h"

void	ft_check_argv(int i, int argc, char **argv, int byte_num)
{
	int	file;
	int	memory_size;
	int	file_num;

	file_num = 0;
	if (i == argc)
		ft_stdin();
	while (i < argc)
	{
		file = open(argv[i], O_RDONLY);
		if (file == -1)
			ft_put_errormsg(argv[i]);
		else
		{
			file_num++;
			ft_put_title(argc, argv, file_num, argv[i]);
			memory_size = measure_size(file);
			file = open(argv[i], O_RDONLY);
			if (byte_num >= 0)
				ft_put_str2(file, byte_num, memory_size);
			else
				ft_put_str(file, memory_size);
		}
		i++;
	}
}
