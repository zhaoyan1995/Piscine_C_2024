/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:58:22 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/01/01 01:02:29 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "ft_cat.h"

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

void	ft_putstr_2(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write(1, str, 1);
		i++;
		str++;
	}
}

void	ft_put_errormsg(char *filename)
{
	char	*msg_error;

	write(2, "cat: ", 5);
	write(2, filename, ft_strlen(filename));
	write(2, ": ", 2);
	msg_error = strerror(errno);
	write(2, msg_error, ft_strlen(msg_error));
	write(2, "\n", 1);
}

void	ft_put_stdin(void)
{
	char	buffer[30720];
	int		byte_size;

	while (1)
	{
		byte_size = read(0, buffer, sizeof(buffer) - 1);
		if (byte_size <= 0)
			break ;
		buffer[byte_size] = '\0';
		write(1, buffer, byte_size);
	}
}
