#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*src_0="EFGHI";
	char	dest_0[30]= "ABCD";	
	printf("*src = \"%s\"\n", src_0);
	printf("dest[30] = \"%s\"\n", dest_0);
	

	printf("strlen(src) = %ld, strlen(dest) = %ld\n", strlen(src_0), strlen(dest_0));
	printf("if size <= strlen(dest)\n");
	printf("size = 0, return value of strlcat = %ld = (strlen(src) + size), dest =%s \n", strlcat(dest_0, src_0, 0), dest_0);	
	char	*src_1="EFGHI";
	char	dest_1[30]= "ABCD";	
	printf("size = 1, return value of strlcat = %ld = (strlen(src) + size), dest =%s \n", strlcat(dest_1, src_1, 1), dest_1);

	char	*src_2="EFGHI";
	char	dest_2[30]= "ABCD";	
	printf("size = 2, return value of strlcat = %ld = (strlen(src) + size), dest =%s \n", strlcat(dest_2, src_2, 2), dest_2);

	char	*src_3="EFGHI";
	char	dest_3[30]= "ABCD";	
	printf("size = 3, return value of strlcat = %ld = (strlen(src) + size), dest =%s \n", strlcat(dest_3, src_3, 3), dest_3);

	char	*src_4="EFGHI";
	char	dest_4[30]= "ABCD";	
	printf("size = 4, return value of strlcat = %ld = (strlen(src) + size), dest =%s \n", strlcat(dest_4, src_4, 4), dest_4);

	char	*src_5="EFGHI";
	char	dest_5[30]= "ABCD";
	printf("if size > strlen(src), here size = the new value of strlen(dest)\n");	
	printf("size = 5, return value of strlcat = %ld = (strlen(src) + strlen(dest)), dest =%s, dest[5] = '\\0' Only  0= 5 - 4 - 1 (size - strlen(dest) -1) available space to stock src\n", strlcat(dest_5, src_5, 5), dest_5);

	char	*src_6="EFGHI";
	char	dest_6[30]= "ABCD";	
	printf("size = 6, return value of strlcat = %ld = (strlen(src) + strlen(dest)), dest =%s, dest[5] = 'E', dest[6] = '\\0' Only 1= 6 - 4 - 1 (size - strlen(dest) -1) available space to stock src\n", strlcat(dest_6, src_6, 6), dest_6);

	char	*src_7="EFGHI";
	char	dest_7[30]= "ABCD";	
	printf("size = 7, return value of strlcat = %ld, dest =%s Only 2= 7 - 4 - 1 (size -strlen(dest)-1) spaces to stock src\n", strlcat(dest_7, src_7, 7), dest_7);

	char	*src_8="EFGHI";
	char	dest_8[30]= "ABCD";	
	printf("size = 8, return value of strlcat = %ld, dest =%s Only 3= 8 - 4 - 1 (size -strlen(dest)-1) spaces to stock src\n", strlcat(dest_8, src_8, 8), dest_8);

	char	*src_9="EFGHI";
	char	dest_9[30]= "ABCD";	
	printf("size = 9, return value of strlcat = %ld, dest =%s Only 4= 9 - 4 - 1 (size -strlen(dest)-1) spaces to stock src\n", strlcat(dest_9, src_9, 9), dest_9);

	char	*src_10="EFGHI";
	char	dest_10[30]= "ABCD";	
	printf("size = 10, return value of strlcat = %ld, dest =%s  5= 10 - 4 - 1 (size -strlen(dest)-1) spaces to stock src, complete the catenate\n", strlcat(dest_10, src_10, 10), dest_10);

	char	*src_11="EFGHI";
	char	dest_11[30]= "ABCD";	
	printf("size = 11, return value of strlcat = %ld, dest =%s 6= 11 - 4 -1 (size -strlen(dest)-1) spaces to stock src \n", strlcat(dest_11, src_11, 11), dest_11);

	char	*src_12="EFGHI";
	char	dest_12[30]= "ABCD";	
	printf("size = 12, return value of strlcat = %ld, dest =%s 7= 12 - 4 -1 (size -strlen(dest)-1) spaces to stock src\n", strlcat(dest_12, src_12, 12), dest_12);

	printf("ATTENTION: The size of dest should always be bigger or equal to size, if not you can not compile the file"); 


	return (0);

}





