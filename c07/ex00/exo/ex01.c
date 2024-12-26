#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	n;
	int	i;
	int	*arr_num;
	int	num;

	while (n <= 0)
	{		
		printf("Please enter the number: ");
		scanf("%d", &n);	
		if (n <= 0)
			printf("Please enter a positive number.\n");	
	}
	arr_num = (int *)malloc(n * sizeof(int));
	if (arr_num == NULL)
		return (1);
	i = 0;
	num = 0;
	while (i < n)
	{
		arr_num[i] = i + 1;
		num = num + arr_num[i];
		i++;
	}
	printf("%d\n", num);
	free(arr_num);
	return (0);
	

		
	



}
