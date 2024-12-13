/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 03:40:02 by ybayart           #+#    #+#             */
/*   Updated: 2024/12/06 18:30:35 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

static void	ft_get_hex(unsigned long long nb, int prev)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb < 16 && prev == 1)
		write(1, "0", 1);
	if (nb >= 16)
	{
		ft_get_hex(nb / 16, 0);
		ft_get_hex(nb % 16, 0);
	}
	else
	{
		write(1, (base + nb), 1);
	}
}

static void	ft_print_addr(unsigned long long addr)
{
	unsigned long long	tmp;
	int					i;

	tmp = addr;
	i = 1;
	while (i++ < 15)
	{
		if (tmp < 16)
			write(1, "0", 1);
		tmp /= 16;
	}
	ft_get_hex(addr, 0);
}

static void	ft_print_data(unsigned char *c, int size)
{
	int		i;

	i = -1;
	while (i++ < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		if (i < size)
		{
			ft_get_hex((unsigned long long)*(c + i), 1);
		}
		else if (i != 16)
		{
			write(1, "  ", 2);
		}
	}
	i = -1;
	while (i++ < size - 1)
	{
		if (*(c + i) <= 31 || *(c + i) >= 127)
			write(1, ".", 1);
		else
			write(1, (c + i), 1);
	}
}

void		*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*c;
	unsigned int	sendsize;

	i = 0;
	c = addr;
	while (i * 16 < size)
	{
		if (i < size / 16)
			sendsize = 16;
		else
			sendsize = size % 16;
		ft_print_addr((unsigned long long)c + (i * 16));
		write(1, ":", 1);
		ft_print_data(c + (i * 16), sendsize);
		write(1, "\n", 1);
		i++;
	}
	return (addr);
}

int	main(void)
{
	char	*str;
	
	str = "Salut les amies,vous savez important de brosser les dents tous les jour!";
	ft_print_memory(str, 30 );	
	return (0);
}
