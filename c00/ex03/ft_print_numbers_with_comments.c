#include<unistd.h>

void ft_print_number(void);

void ft_print_number(void)
{
	char number='0';
	while(number<='9')
	{
		write(1,&number,1);
		number++;
	}
}

int main()

{
	ft_print_number();
	return 0;
}
