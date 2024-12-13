#include<unistd.h> //To apply the write function, you must include the header file <unistd.h> #include<stdio.h>
#include<stdio.h>
void ft_putchar(char *c); //prototype of function ft_putchar.


void ft_putchar(char *c) //char *c is a pointer to a character. It means that c is a variable designed to store the memory address of a char (or the first character in a string, which is a sequence of characters in C). The behavior of char *c depends on how it is used. It could point a single character or a string, in this case, it is a string, because it contains more than one character.
{
	write(1,c,3); //function write, the first "1" is to define  where I want to put, 1 means the STDOUT (Standard Output), c means we catch the parameter as the variable to apply the function "write". the "3" means the size of the string, it is 3 bytes= 3 letters.
}

int main(void) //We can put nothing in the () but it is better to indicate "void" in () to specify that we don't have parameters that are applied in our function main().
{
	ft_putchar("abcdefg\n"); //Remeber use "" to put the parameter because it is a string to put. Because in the write function, we only allow first 3 characters to be written, so the output can only display the 1st 3 letters of "abcdefg".	
	return 0;
}
