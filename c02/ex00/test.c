#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*a = "Hello World!";
	char	b[] = "Hello World!";
	int		size1=sizeof(a)/sizeof(a[0]);
	int		size2=strlen(a);
	int		size3=sizeof(b)/sizeof(b[0]);
	int		size4=strlen(b);

	printf("size1=%d, size2=%d\n", size1, size2);
	printf("size3=%d, size4=%d\n", size3, size4);
	return 0;
}
