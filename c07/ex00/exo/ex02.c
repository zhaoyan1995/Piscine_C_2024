#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	**arr_num;
	int	row;
	int	col;
	int	num;
	int	i;
	int	j;
	int	k;

	printf("Please enter the row of arr_num.\n");
	scanf("%d", &row);
	printf("Please enter the col of arr_num.\n");
	scanf("%d", &col);
	if (row <= 0 || col <= 0)
	{
		printf("please enter the positive number for row and col.\n");	
		return(1);
	}
	arr_num = (int **)malloc(row * sizeof(int *));
	if (arr_num == NULL)
	{
		printf("insufficient memory row.\n");
		return (1);
	}
	i = 0;
	while (i < row)
	{
		arr_num[i] = (int *)malloc(col * sizeof(int));
		if (arr_num[i] == NULL)
		{ 
			printf("insufficient memory col.\n");
			k = 0;
			while (k < i)
			{
				free(arr_num[k]);
				k++;
			}		
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			printf("please enter a number for arr_num[%d][%d]: ", i, j);	
			scanf("%d", &num);	
			arr_num[i][j] = num;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			printf("%d ", arr_num[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	i = 0;
	while (i < row)
	{
		free(arr_num[i]);
		i++;
	}
	free(arr_num);
	return (0);
}
