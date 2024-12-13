#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char	*binary;
	char	binary_writable[32];
	int		i;
	int		number_decimal;
	int		j;

	i = 0;
	binary = "11111111111111111111111111111111";
	while (*binary != '\0')
	{
		binary_writable[i] = *binary;
		binary++;
		i++;
	}	
	number_decimal = 3;	
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
	write(1, binary_writable, 32);	
	printf("i = %d\n", i);	
	j = 31;
	if (binary_writable[j] == '1')
	{
		binary_writable[j] = '0';
		printf("bw j = %c\n",binary_writable[j]);
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
	write(1, "\n", 1);	
	write(1, binary_writable, 32);		

	return (0);


}
