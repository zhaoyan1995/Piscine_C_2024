ATTENTION:

When we allocate a memory to a char *
here is the correct format:
example 
char    *str;

str = (char *)malloc(sizeof(char) * 4);

DO NOT WRITE sizeof(char *) for str

sizeof(char *) that is for the **str 

The same thing for the structure data type.

//We declare a type of structure t_stock_str and it is a pointer
t_stock_str  *result;

Incorrect format:
result = (t_stock_str *)malloc(sizeof(t_stock_str *) * (ac + 1));

Correct format: 
result = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));

