/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:27:47 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/11/28 19:47:11 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n);

void	ft_is_negative(int n)
{
	char	negative;
	char	positive;

	if (n < 0)
	{
		negative = 'N';
		write(1, &negative, 1);
	}
	else
	{
		positive = 'P';
		write(1, &positive, 1);
	}
}

int	main(void)
{
	ft_is_negative(-10);
	return (0);
}
