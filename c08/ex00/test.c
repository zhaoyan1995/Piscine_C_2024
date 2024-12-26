#include "/home/yan/Code_C/c08/ex00/ft.h"
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = 2;	
	b = 6;
	ft_putchar('l');
	ft_putchar('\n');
	ft_swap(&a, &b);
	printf("a = %d b = %d\n", a, b);
	return (0);
}
