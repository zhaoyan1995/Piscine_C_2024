The function ft_strstr is to locate a sub_string from the source string

Example1: 
source_string = "HelloWorld!!!"
sub_string = "Wor";

ft_strstr (source_string, sub_string)

the return value of this function is "World!!!"
it will locate the position of the 1st element of sub_string and print the source_string from this element "W" until the end.

Example2:
source_string = "HelloWorld!!!"
sub_string = "World?"

the return value  of this function is NULL (NO OUTPUT for this function or "" an empty char*) 
It is NOT A GOOD IDEAL TO RETURN NULL DIRECTLY, because it will crash the system, so we can create a char* that store an empty "" or "\0" so if it will not match then it will not print anything at then end.

because we do not have "?" in the source_string.

Example3:
source_string = "HelloWorld!!!"
sub_string = ""

the return value  of this function is the entier source_string because the sub_string is empty! 


The logic behind the function ft_strstr:

char    *ft_strstr(char *str, char *to_find)

the return value should be a char pointer.
*str is the source_string.
*to_find is the sub_string.  

ex:
char    *str
char    *fin 

str = "ABCDEF";
fin = "DE";

i the index for str;
j the index for fin;

when i = 0;
when j = 0;
make sure that str[0] != '\0' fin[O] != '\0';
we compare: 
str[0] (here 0 = i + j) vs fin[0] (here j = 0) => not equal => NO NEED TO COMPARE str[1] vs fin[1]; BREAK inner LOOP

str[0]|str[1]|str[2]|str[3]|str[4]|str[5]|   
  A   |  B   |  C   |  D   |  E   |  F   |
fin[0]|fin[1]|
  D   |  E   |

when i = 1;
when j = 0;

make sure that str[1] != '\0' fin[0] != '\0';
we compare:
str[1] (here 1 = i + j) vs fin[0] (here j = 0)=> not equal => NO NEED TO COMPARE str[2] vs fin[1]; BREAK inner LOOP

str[0]|str[1]|str[2]|str[3]|str[4]|str[5]| 
  A   |  B   |  C   |  D   |  E   |  F   |
      |fin[0]|fin[1]|
      |  D   |  E   |


when i = 2;
when j = 0;

make sure that str[2] != '\0' fin[0] != '\0';
we compare:
str[2] (here 1 = i + j) vs fin[0](here j = 0) => not equal => NO NEED TO COMPARE str[3] vs fin[1]; BREAK inner LOOP

str[0]|str[1]|str[2]|str[3]|str[4]|str[5]| 
  A   |  B   |  C   |  D   |  E   |  F   |
             |fin[0]|fin[1]|
             |  D   |  E   |


when i = 3;
when j = 0;

make sure that str[3] != '\0' fin[0] != '\0';
we compare:
str[3] (here 3 = i + j)vs fin[0](here j = 0) => EQUAL!!! we allow j++ to compare the next!

i is always 3 here!!!
when j = 1;

make sure that str[4] != '\0' fin[0] != '\0';
we compare:
str[4] (here 4 = i + j)vs fin[1](here j = 1) => EQUAL!!! we allow j++;
fin[2] == '\0' here, so we return directly str + i, even i = 3 and we didn't complete the str while loop but it is no need to continue to compare str[4] vs fin[0] and str[5] vs fin[1]; because this function take into account only the 1st match! and print the str+i immediately
str[0]|str[1]|str[2]|str[3]|str[4]|str[5]| 
  A   |  B   |  C   |  D   |  E   |  F   |
                    |fin[0]|fin[1]|
                    |  D   |  E   |

The last one is the only one that complete the inner while fin loop
The return value is char * type so it will print DEF at the end.



