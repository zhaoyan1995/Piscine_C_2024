#include<stdio.h>

void ft_swap(int *a, int *b);

void ft_swap(int *a, int *b)
{	
	int x; //we create an int variable A to stock the value of the pointer variable *a
	x=*a; 
	int y;
	y=*b; //we create an int variable B to stock the value of the pointer variable *b
	*a=y; //we switch the value of the pointer 
	*b=x;
}

int main(void)
{
	
	int a1;
	a1=43;	
	int b1;
	b1=26;
	printf("Before using the function swap a=%d b=%d\n",a1,b1); 
	ft_swap(&a1,&b1); //here *a=&a1, *b=&b1 we give the address for the pointer *a and *b, so that *a could obtain the value of a1 , and *b can obtain the value of b1; 
	printf("After using the function swap a=%d b=%d\n",a1,b1);
	return 0;
}

