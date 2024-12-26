#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int	n;
	int	*arr_num;
	int	i;

	printf("Please enter the number: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("Please enter a positive number.\n");		
		return (1);
	}
	arr_num = (int *)malloc(n * sizeof(int));
	i = 0;
	if (arr_num == NULL)
		return (1);
	while (i < n)
	{
		arr_num[i] = i + 1;
		i++;
	}
	i = 0;
	while (i < n)
	{
		printf("%d ", arr_num[i]);
		i++;
	}
	printf("\n");
	free(arr_num);
	return (0);
}
