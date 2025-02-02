/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:54:25 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/01/12 01:59:26 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

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

void	ft_put_errmsg_1(char *file_name)
{
	char *errmsg;	

	errmsg = strerror(errno);	
	write(2, "hexdump: ", 9);
	write(2, file_name, ft_strlen(file_name));
	write(2, ": ", 2);
	write(2, errmsg, ft_strlen(errmsg));
	write(1 , "\n", 1);
}

int	measure_file_size(char *filename)
{
	int		file;
	int 		byte_read;
	int		file_size;
	char	buffer[1024];

	file = open(filename, O_RDONLY);
	byte_read = read(file, buffer, sizeof(buffer));
	if (file != -1)		
		file_size = byte_read;
	else
		return (0);
	while (byte_read > 0)
	{
		byte_read = read(file, buffer, sizeof(buffer));
		file_size += byte_read;
	}
	close(file);	
	return (file_size);
}

int	measure_size_num_hex(int num_dec)
{
	int 	size_num_hex;

	size_num_hex = 0;
	while (num_dec /16 > 0)
	{
		num_dec /= 16;
		size_num_hex++;
	}
	return (size_num_hex);
}

void	ft_convert_hex(int num_dec)
{
	int		size_num_hex;
	int		i;
	char	*num_hex;
	char	*base_hex;

	base_hex = "0123456789abcdef";
	size_num_hex = measure_size_num_hex(num_dec);
	num_hex = (char *)malloc(size_num_hex + 1);
	i = size_num_hex;
	if (size_num_hex == 0)
		write(1, "0", 1);
	while (i >= 0)
	{
		num_hex[i--] = base_hex[num_dec % 16];
		num_dec /= 16;	
	}
	i = 0;
	while (i < size_num_hex + 1)
		write(1, &num_hex[i++], 1);	
	free(num_hex);
}

void	ft_non_printable(char *str)
{
	int	num_dec;

	num_dec = (int)(*str);
	if (num_dec == 7)
		write(1, "\\a", 2);
	else if (num_dec == 8)
		write(1, "\\b", 2);
	else if (num_dec == 9)
		write(1, "\\t", 2);
	else if (num_dec == 10)
		write(1, "\\n", 2);
	else if (num_dec == 11)
		write(1, "\\v", 2);
	else if (num_dec == 12)
		write(1, "\\f", 2);
	else if (num_dec == 13)
		write(1, "\\r", 2);
	else if (num_dec == 0)
		write(1, "\\0", 2);
}

void	ft_put_start(int i)
{
	char	start[7];
	char	*base_hex;
	int	nb_non_zero;
	int	num_i;
	int	j;

	j = 0;
	while (j < sizeof(start))
		start[j++] = '0';
	base_hex = "0123456789abcdef";
	nb_non_zero = 0;
	num_i = i;
	while (num_i > 0)
	{
		num_i/= 16;
		nb_non_zero++;
	}
	j--;
	while (nb_non_zero > 0 && j >= 0)
	{
		start[j] = base_hex[i % 16];
		j--;
		nb_non_zero--;
		i /= 16;
	}
	write(1, &start, sizeof(start));
	write(1 , " ", 1);
}

char	*open_read_file(char *filename)
{
	int 	file;
	int	measure_size;
	int	byte_size;
	char	*buffer;

	file = open(filename, O_RDONLY);
	if (file == - 1)
		return NULL;
	measure_size = measure_file_size(filename);
	buffer = (char *)malloc(measure_size + 1);
	byte_size = read(file, buffer, measure_size + 1);
	close(file);
	return (buffer);
}

void	ft_put_hexdec(int argc, char **argv)
{
	int		i;
	int		i2;
	int		i3;
	int		j;
	int		j2;
	int		line;
	int		file_size;
	int		num_dec;
	int		num_dec2;
	char	*buffer;
	

	j = 1;		
	j2 = 1;
	i2 = 0;
	i = 0;
	line = 1;
	file_size = 0;
	if (argv[1][0] == '-' && argv[1][1] == 'c')
		j++;
	if (argv[1][0] == '-' && argv[1][1] == 'c')
		write(1, " ", 1);
	while (open(argv[j], O_RDONLY) == -1)
	{
		buffer = open_read_file(argv[j]);
		ft_put_errmsg_1(argv[j]);
		j++;
	}	
	i = 0;
	file_size = 0;
	while (j < argc)
	{		
		file_size = file_size + measure_file_size(argv[j]);
		while (i < file_size)
		{	
			i3 = 1;
			while (line * 16 - file_size <= 16 && line * 16 - file_size > 0 && j + i3 != argc && i2 % 16 == 0)
			{	
				if (open(argv[j + i3], O_RDONLY) == -1)
					ft_put_errmsg_1(argv[j + i3]);
				else
				{
					close(open(argv[j + i3], O_RDONLY));
					break ;
				}
				i3++;
			}	
			buffer = open_read_file(argv[j]);
			if (i2 % 16 == 0)
			{	
				ft_put_start(i2);	
				line++;
			}
			num_dec = (int)buffer[i];
			num_dec2 = (int)buffer[i + 1];
			if (num_dec2 != 0)
			{
				ft_convert_hex(num_dec2);
				ft_convert_hex(num_dec);
				i+=2;
				i2+=2;
				write(1, " ", 1);
			}
			else
				break ;
			if (i2 % 16 == 0)
			{
				
				write(1, "\n", 1);
			}
			i3 = 1;
		
		}	
		free(buffer);
		j++;
		if (j < argc)
		{	
			buffer = NULL;
			while (j < argc)
			{
				if (open(argv[j], O_RDONLY) == -1)
					j++;
				else 
				{	
					buffer = open_read_file(argv[j]);
					break ;
				}
			}
			if (file_size % 2 != 0 && buffer != NULL)
			{
				ft_convert_hex(buffer[0]);
				ft_convert_hex(10);
				write(1, " ", 1);
				i = 1;
				i2 += 2;
			}
			else if (file_size % 2 == 0 && buffer != NULL)
			{
				ft_convert_hex(buffer[1]);	
				ft_convert_hex(buffer[0]);
				write(1, " ", 1);
				i = 2;
				i2 += 2;
			}	
			/*if (i2 % 16 == 0)
				write(1, "\n", 1);*/
		}	
		else 
			break ;
	}
	if (file_size % 2 != 0)
	{
		write(1, "000a", 4);
		i2++;
	}
	if (i2 % 16 != 0)	
	{
		write(1, "\n", 1);
		ft_put_start(i2);		
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	file;
	int	nb_file;
	
	if (argc == 1)
		while (1);
	i = 1;
	if (argv[1][0] == '-' && argv[1][1] == 'c')
	{
		if (argc == 2)
			while (1);
		i++;
	}
	nb_file = 0;
	while (i < argc)
	{
		file = open(argv[i], O_RDONLY);
		if (file != - 1)
			nb_file++;
		close(file);
		i++;
	}
	i = 1;
	if (nb_file == 0)
	{	
		while (i < argc)
		{
			file = open(argv[i], O_RDONLY);	
			ft_put_errmsg_1(argv[i]);
			close(file);	
			i++;
		}	
		write(2, "hexdump: all input file arguments failed\n", 41);
		return (1);
	}
	else
		ft_put_hexdec(argc, argv);
	return (0);
}
