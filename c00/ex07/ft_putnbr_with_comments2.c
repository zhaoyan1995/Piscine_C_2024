#include <unistd.h>

void	ft_putnbr(int nb);

void	ft_putnbr(int nb )
{
	char	digit;

	if (nb == 0) //Base case of recursive process, when nb==0
	{
		write(1, "0", 1); //if nb is 0, we print the "0" we complete this function
		return ;
	}
	if (nb < 0)//if nb is negative, then we need to add "-" before we start print the digits
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			write(1, "2", 1);
			nb = nb % 1000000000;
		}
		ft_putnbr(-nb);
	}
	else//if nb is positive
	{
		if (nb / 10 != 0) //if nb /10 != 0, that means nb has only one digit
			ft_putnbr(nb / 10);// we start RECURSIVE process by dividing nb/10 until nb/10 =0  then we stop the recursive process
		//2 cases for the instruction below, 1.if the original nb has only one digit, then we skip the recursive function, 2. if nb has at least 2 digits, then nb will be divided by nb until it has only one digit, then it will becom the same case as 1
		
		// ex; nb=365, then nb/10=36 then nb/10=3 then nb/10=0, so we go back from the lowest level of recursive process, when nb=3 then write digit=nb%10=3%10=3, then digit=nb%10=36%10=6 then digit=nb%365=5 then we finish the whole process
		digit = nb % 10 + '0';//we start to return the value one by one from the right side of the original nb to the left one 
		write(1, &digit, 1); //we print the digit one by one
	}
}

int	main(void)
{
	ft_putnbr(-40);
	return (0);
}
