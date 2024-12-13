#include<unistd.h>

void ft_putchar(char c); //prototype of function ft_putchar.



void ft_putchar(char c) //char c :a variable c that stores a single character. It is not a pointer, so it directly holds the value of the character (e.g., 'A', 'z', etc.) rather than a memory address.
{
	write(1,&c,1); //first 1 = STDOUT standard output &c means the variable c that was designed as parameter in ft_putchar function at the beginning. senconde "1" means we only allowed to print the 1 byte of the content in variable c.
}

int main()
{
	ft_putchar('a'); //' ' need to be added between content that need to be displayed. If not it is not going to be considered as a character. 
	return 0;
}
