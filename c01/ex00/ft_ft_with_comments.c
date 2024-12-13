#include<stdio.h>

void ft_ft(int *nbr);

void ft_ft(int *nbr)
{
	*nbr=42;	
	return;
}

int main(void)
{
	int number=2; 
	int *NBR; //declare a pointer variable
	NBR=&number; //1st thing after creating the pointer variable, GIVE him an adress! So the pointer variable can pick up the value of number.
	ft_ft(NBR); //introducee the *NBR into the ft_ft function but do not use * in the function
	printf("%d\n",number);
	return 0;
} 


//Once the adresse of a variable is pointed by a pointer variable then the value of this pointed variable will become 42
