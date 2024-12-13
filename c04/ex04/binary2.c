#include <unistd.h>
#include <stdio.h>

void	plus_one_binary(char binary_writable[], int i)
{
	int	j;

	j = 31;	
	if (binary_writable[j] == '1')
	{
		binary_writable[j] = '0';	
		j--;	
		while ( j > i)
		{
			if (binary_writable[j] == '1')
			{
				binary_writable[j] = '0';
				j--;
			}
			else 
			{
				binary_writable[j] = '1';
				break ; 
			}
		}
	}
	else
		binary_writable[j] = '1';
}

void	reverse_binary(int number_decimal)
{
	char	binary_writable[32];
	int		i;

	i = 0;
	while (i < 32)
	{
		binary_writable[i] = '1';
		i++;
	}		
	i -= 1;
	while (i >= 0 && number_decimal != 0)
	{
		if (number_decimal %  2 != 0)
		{
			binary_writable[i] = '0';
		}
		i--;
		number_decimal /= 2;
	}		
	plus_one_binary(binary_writable, i);
	write(1, binary_writable, 32);
	printf("\n");
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (nbr < 0)	
		reverse_binary(-nbr);
}

int	main(void)
{
	int		number_decimal;
	char	*base_binary;

	base_binary = "01";
	number_decimal = -250;
	ft_putnbr_base(number_decimal, base_binary);
	return (0);
}
