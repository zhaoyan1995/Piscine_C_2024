#include<stdio.h>
int main(void)
{
	char a[4];
	char *b;

	a[0] = 'A';
	a[1] = 'M';
	a[2] = 'I';
	a[3] = '\0';
	b = "AMI";
	printf("The adress of array a is	%p. print type : %%p ""&a""\n",&a);
	printf("The adress of element a[0] is	%p. print type : %%p ""&a[0]"" \n",&a[0]);	
	printf("The adress of pointer *b is	%p. print type : %%p ""&b""\n",&b);
	printf("The adress of array b is	%p. print type : %%p ""b""\n",b);
	printf("The adress of element b[0] is	%p. print type : %%p ""(void *)&b[0]""\n", (void *)&b[0]);
	printf("The adress of element b[1] is	%p. print type : %%p ""(void *)&b[1]""\n", (void *)&b[1]);
	printf("The adress of element b[2] is	%p. print type : %%p ""(void *)&b[2]""\n", (void *)&b[2]);
	printf("The adress of element b[3] is	%p. print type : %%p ""(void *)&b[3]""\n", (void *)&b[3]);
	printf("The value of element b[1] is	%c. 		print type : %%c ""*(b+1)""\n", *(b+1));	
	printf("The value of element b[1] is	%c.		print type : %%c ""b[1]""\n", b[1]);
	printf("The value of array b is		%s. 		print type : %%s ""b""\n", b);
	
	return (0);
}
