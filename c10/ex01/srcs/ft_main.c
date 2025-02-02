/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:58:22 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/01/01 01:03:23 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft_cat.h"

int	main(int argc, char **argv)
{
	int		file;
	int		i;
	int		byte_size;
	char	buffer[30720];

	if (argc == 1)
		ft_put_stdin();
	i = 1;
	while (i < argc)
	{
		file = open(argv[i], O_RDONLY);
		if (file == -1)
			ft_put_errormsg(argv[i]);
		else
		{
			byte_size = read(file, buffer, sizeof(buffer) - 1);
			buffer[byte_size] = '\0';
			ft_putstr_2(buffer, byte_size);
			close(file);
		}
		i++;
	}
	return (0);
}
