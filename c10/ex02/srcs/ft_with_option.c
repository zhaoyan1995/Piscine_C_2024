/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_with_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:28:27 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/01/04 22:15:16 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_tail.h"

int		ft_find_num(char c);
int		ft_check_nbr(char *str);
void	ft_put_str2(int file, int byte_num, int memory_size);
void	ft_option(int argc, char **argv);

int	ft_find_num(char c)
{
	int		num;
	int		i;
	char	base_decimal[10];

	i = 0;
	while (i < 10)
	{
		base_decimal[i] = i + '0';
		i++;
	}
	num = 0;
	while (num < 10)
	{
		if (c == base_decimal[num])
			return (num);
		num++;
	}
	return (-1);
}

int	ft_check_nbr(char *str)
{
	int	num;

	num = 0;
	while (*str != '\0')
	{
		if (ft_find_num(*str) >= 0)
			num = num * 10 + ft_find_num(*str);
		else
			return (-1);
		str++;
	}
	return (num);
}

void	ft_put_str2(int file, int byte_num, int memory_size)
{
	int		byte_read;
	int		i;
	char	*buffer;

	buffer = (char *)malloc(memory_size + 1);
	byte_read = read(file, buffer, memory_size);
	buffer[byte_read] = '\0';
	i = 0;
	while (i < byte_read - byte_num)
	{
		i++;
	}
	while (i < byte_read)
	{
		write(1, &buffer[i], 1);
		i++;
	}
	close(file);
	free(buffer);
}

void	ft_option(int argc, char **argv)
{
	int	i;
	int	byte_num;

	if (argc == 2)
	{
		write(2, "tail: option requires an argument -- 'c'\n", 41);
		return ;
	}
	byte_num = ft_check_nbr(argv[2]);
	if (byte_num < 0)
	{
		write(2, "tail: invalid number of bytes: '", 32);
		if (argv[2][0] == '-')
			argv[2]++;
		write(2, argv[2], ft_strlen(argv[2]));
		write(2, "'\n", 2);
	}
	else
	{
		i = 3;
		ft_check_argv(i, argc, argv, byte_num);
	}
}
