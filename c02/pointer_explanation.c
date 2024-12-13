/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_explanation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:22:42 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2024/11/30 15:32:00 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>	

//Do not put "char	adress_of_a;"
//You CAN'T save the adress of a varaible by using 
//a char type variable or int variable,
//If so, you will fail during the compilation!

int	main(void)
{
	int		a;
	int		*ptr;

	a = 32;
	ptr = &a;
	printf("1. The value of a is 	%d.			print type 	%%d\n", a);
	printf("2. The adress of a is 	%p.		print type 	%%p\n", &a);
	printf("3. The value of ptr is	%p.		print type 	%%p\n", ptr);
	printf("4. The value of *ptr is %d.			print type 	%%d\n", *ptr);
	printf("5. The adress of ptr is %p.		print type 	%%p\n", &ptr);
	return (0);
}
