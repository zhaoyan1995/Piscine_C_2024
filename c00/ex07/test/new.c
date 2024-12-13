#include <unistd.h>
#include <stdio.h>
void function(int c)
{
	//how to diplay the first number a without convert it from int type to char type?
	int a=c/10+48;	
	write(1,&a,1);
	//how to display the second number b without convert it from int type to char type?
	int b=c%10+48;
	write(1,&b,1);
	printf("\n");
	//how to display the first number d in type char at the beginning.
	char d=c/10+'0';
	write(1,&d,1);
	//how to display the second number e in type char at the beginning.
	char e=c%10+'0';
	write(1,&e,1);
	printf("\n");
	char C='8';
	write(1,&C,1);

}

int main()
{
	function(34);
	return 0;
}
