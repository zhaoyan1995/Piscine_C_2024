/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:28:27 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/01/04 21:59:06 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "ft_tail.h"

int		ft_strlen(char *str);
int		measure_size(int file);
void	ft_stdin(void);
void	ft_put_errormsg(char *filename);
void	ft_put_title(int argc, char **argv, int file_num, char *str);

void	ft_stdin(void)
{
	while (1)
		read (0, 0, 0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

void	ft_put_errormsg(char *filename)
{
	char	*str;

	str = strerror(errno);
	write(2, "tail: cannot open '", 20);
	write(2, filename, ft_strlen(filename));
	write(2, "' for reading: ", 16);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

int	measure_size(int file)
{
	char	buffer[1024];	
	int		file_size;
	int		byte_read;

	byte_read = read(file, buffer, sizeof(buffer));
	file_size = byte_read;
	while (byte_read > 0)
	{
		byte_read = read(file, buffer, sizeof(buffer));
		file_size += byte_read;
	}
	close(file);
	return (file_size);
}

void	ft_put_title(int argc, char **argv, int file_num, char *str)
{
	if (argv[1][0] == '-' && argv[1][1] == 'c' && argc > 4)
	{
		if (file_num != 1)
			write(1, "\n", 1);
		write(1, "==> ", 5);
		write(1, str, ft_strlen(str));
		write(1, " <==\n", 5);
	}
	else if ((argv[1][0] != '-' || argv[1][1] != 'c') && argc > 2)
	{
		if (file_num != 1)
			write(1, "\n", 1);
		write(1, "==> ", 5);
		write(1, str, ft_strlen(str));
		write(1, " <==\n", 5);
	}
}
