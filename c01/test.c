#include<stdio.h>

void ft(int *********nb)
{
	*********nb=42;
}

int main(void)
{
	int n;
	int *p1;
	int **p2;
	int ***p3;
	int ****p4;
	int *****p5;
	int ******p6;
	int *******p7;
	int ********p8;
	int *********p9;
	p1=&n;
	p2=&p1;
	p3=&p2;
	p4=&p3;
	p5=&p4;
	p6=&p5;
	p7=&p6;
	p8=&p7;
	p9=&p8;
	ft(p9);
	printf("%d\n",n);
	return 0;
}
