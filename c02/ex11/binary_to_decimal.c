#include <stdio.h>

int ft_pow(int a, int i)
{	
	int result = 1;	
	while (i > 0)
	{
		result = result*a;
		i--;
	}
	return (result);
}

int binary_to_decimal(long long binary)
{
	int i = 0;	
	int remainder;
	int decimal = 0;
	while(binary != 0)
	{
		remainder = binary  % 10;
		binary = binary / 10;
		decimal = decimal + remainder*ft_pow(2,i);
		i++;
	}
	return decimal;
}

int	main(void)
{
	int a = 2;
	int b = 3;
	long long n = 001;
	printf("%d\n", ft_pow(a, b));
	printf("%d\n", binary_to_decimal(n));
	

	return (0);
}
	


