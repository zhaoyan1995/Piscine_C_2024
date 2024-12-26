#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*str;
	char	*dest;
	int	i;
	int	j;
	
	printf("Please enter a string: ");	
	scanf("%[^\n]", str);	
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	printf("%ld\n", strlen(str));
	printf("i = %d\n", i);
	dest = (char *)malloc(i * sizeof(char));
	j = 0;
	while (j < i)
	{
		dest[j] = str[j];
		j++;
	}
	printf("dest is %s.", dest);	
	free(dest);
	
	return (0);
	
		

}
