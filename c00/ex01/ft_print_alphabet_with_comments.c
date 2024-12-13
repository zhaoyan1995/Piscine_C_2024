#include<unistd.h>

void ft_print_alphabet(void); //First "void" => this function don't return any value. The second "void" => this function don't take any parameter.


void ft_print_alphabet(void)
{
	char letter='a';
	while(letter<='z')
	{
		write(1,&letter,1);
		letter++;
	}
}


int main(void) //The main function don't take any parameter. 
{
	ft_print_alphabet();
	return 0;
}
