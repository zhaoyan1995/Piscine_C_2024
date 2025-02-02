/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:44:12 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/29 22:27:56 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <ft_display_file.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_error_arg(int argc)
{
	char	*no_argument;
	char	*too_many_argument;

	no_argument = "File name missing.\n";
	too_many_argument = "Too many arguments.\n";
	if (argc <= 1)
	{
		ft_putstr(no_argument);
		return ;
	}
	if (argc > 2)
	{
		ft_putstr(too_many_argument);
		return ;
	}
}

void	ft_error_file_name()
{
	char	*error_message;

	error_message = "Cannot read file.\n";
	ft_putstr(error_message);
	return ;
}
