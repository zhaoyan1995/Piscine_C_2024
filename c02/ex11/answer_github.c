/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer_github.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 22:18:10 by asoursou          #+#    #+#             */
/*   Updated: 2024/12/04 22:46:19 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

void    ft_puthex(unsigned char c)
{
        char *base;

        base = "0123456789abcdef";
        ft_putchar(base[c / 16]);
        ft_putchar(base[c % 16]);
}

void    ft_putstr_non_printable(char *str)
{
        while (*str)
        {
                if (*str < ' ' || *str == 127)
                {
                        ft_putchar('\\');
                        ft_puthex(*str);
                }
                else
                        ft_putchar(*str);
                str++;
        }
}

int     main(void)
{
        char *str;

        str = "Hello\vtu vas bien?";
        ft_putstr_non_printable(str);
        return (0);
}
