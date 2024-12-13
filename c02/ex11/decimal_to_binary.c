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

long long decimal_to_binary(int decimal)
{
	int i = 0;	
	int remainder;
	int binary = 0;
	while(decimal != 0)
	{
		if (decimal % 2 != 0)
		{
			binary = binary + 1*ft_pow(10,i); 
		}	
		decimal = decimal / 2;
		i++;
	}
	return binary;
}

int	main(void)
{
	int decimal;
	
	decimal = 25;
	printf("%lld\n", decimal_to_binary(decimal));
	return (0);
}
	


