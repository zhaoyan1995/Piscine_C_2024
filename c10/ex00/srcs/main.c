/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:44:12 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/29 22:35:06 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_display_file.h>
#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		file;
	int		byte_size;
	char	buffer[3000000];

	if (argc <= 1 || argc > 2)
	{
		ft_error_arg(argc);
		return (1);
	}
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		ft_error_file_name();
		return (1);
	}
	byte_size = read(file, buffer, sizeof(buffer) - 1);
	buffer[byte_size] = '\0';
	ft_putstr(buffer);
	if (file != -1)
		close(file);
	return (0);
}
