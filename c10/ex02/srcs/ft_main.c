/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:10:55 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/01/04 22:19:09 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	main(int argc, char **argv)
{
	if (argc <= 1)
		ft_stdin();
	else
	{
		if (argv[1][0] == '-' && argv[1][1] == 'c')
			ft_option(argc, argv);
		else
			ft_check_argv(1, argc, argv, -1);
	}
	return (0);
}
