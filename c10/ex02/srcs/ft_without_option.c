/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_without_option.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:28:27 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/01/04 22:01:14 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_tail.h"

int		ft_count_nb_brkline(char *buffer, int byte_read);
void	ft_put_str(int file, int memory_size);

int	ft_count_nb_brkline(char *buffer, int byte_read)
{
	int	nb_brkline;
	int	i;

	nb_brkline = 0;
	i = 0;
	nb_brkline = 0;
	while (i < byte_read)
	{
		if (buffer[i] == '\n')
			nb_brkline++;
		i++;
	}
	return (nb_brkline);
}

void	ft_put_str(int file, int memory_size)
{
	int		byte_read;
	int		nb_brkline;
	int		nb_brkline2;
	int		i;
	char	*buffer;

	buffer = (char *)malloc(memory_size + 1);
	byte_read = read(file, buffer, memory_size);
	buffer[byte_read] = '\0';
	nb_brkline = ft_count_nb_brkline(buffer, byte_read);
	if (nb_brkline <= 10)
		write(1, buffer, byte_read);
	i = 0;
	nb_brkline2 = 0;
	while (i < byte_read && nb_brkline > 10)
	{
		if (buffer[i] == '\n' && nb_brkline2 != nb_brkline - 10)
			nb_brkline2++;
		i++;
		if (nb_brkline2 == nb_brkline - 10)
			write(1, &buffer[i], 1);
	}
	close(file);
	free(buffer);
}
