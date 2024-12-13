#include<stdio.h>

void modify_value(int *ptr)
{
	*ptr=42;
}

int main()
{
	int x=12;
	int *p=&x;
	modify_value(p);
	printf("%d\n",x);
	return 0;
}
