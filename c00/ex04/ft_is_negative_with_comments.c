#include<unistd.h>

void ft_is_negative(int n);

void ft_is_negative(int n)
{
	if(n<0)
	{
		char negative='N';	
		write(1,&negative,1);
	}
	else 
	{
		char positive='P';	
		write(1,&positive,1);
	}
}


int main(void)
{
	ft_is_negative(-10);
	return 0;
