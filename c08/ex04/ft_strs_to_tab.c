/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:42:09 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/12/26 16:20:02 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_copy(char *str)
{
	int		i;
	int		size;
	char	*copy;	

	i = 0;
	size = ft_strlen(str);
	copy = (char *)malloc(size + 1);
	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int	i;	
	t_stock_str	*tab;

	tab = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_copy(tab[i].str);
		i++;
	}
	tab[i].size = 0;
	tab[i].str = 0;
	tab[i].copy = 0;
	return (tab);
}

/*int	main(void)
{
	char	*strs[3];
	int		ac;
	int		i;
	t_stock_str	*tab;

	strs[0] = "Coucou, Lilou";
	strs[1] = "Comment tu vas?";
	strs[2] = NULL;
	ac = 2;
	tab = ft_strs_to_tab(ac, strs);
	i = 0;
	while (tab[i].size != 0)
	{
		printf("tab[i].size = %d \n", tab[i].size);
		printf("tab[i].str = %s \n", tab[i].str);
		printf("tab[i].copy = %s\n ", tab[i].copy);
		free(tab[i].copy);
		i++;
	}
	free(tab);
	return (0);
}*/
