/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:42:09 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/26 16:38:32 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "/home/yan/Code_C/c08/ex04/ft_stock_str.h"
#include <stdlib.h>

void	ft_put_str(char *str)
{
	int	i;

	i = 0;
	write(1, "\"", 1);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\"", 1);
	write(1, "\n", 1);
}

void	ft_put_nbr(int nbr)
{
	char	c;

	if (nbr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nbr / 10 != 0)
	{
		ft_put_nbr(nbr / 10);
	}
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int		len;	

	while (par -> str != NULL)
	{
		ft_put_str(par -> str);
		len = ft_strlen(par -> str);
		ft_put_nbr(len);
		write(1, "\n", 1);
		ft_put_str(par -> copy);
		par++;
	}
}

int	main(void)
{
	char		*strs[3];
	int			ac;
	int			i;
	t_stock_str	*tab;

	strs[0] = "Coucoudfzerfsdffffffffffffffffffffffffffffffffeqrfzerzr";
	strs[1] = "fzerfsfsd erzed de";
	strs[2] = NULL;
	ac = 2;
	tab = ft_strs_to_tab(ac, strs);
	ft_show_tab(tab);
	i = 0;
	while (tab[i].copy != NULL)
	{
		free(tab[i].copy);
		i++;
	}
	free(tab);
	return (0);
}
