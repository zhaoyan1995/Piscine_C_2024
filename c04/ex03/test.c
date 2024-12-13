#include <stdio.h>
#include <stdlib.h>

int main() {
    char str1[] = "0233";
    char str2[] = "42 with text";
    char str3[] = "   -5678-";
    char str4[] = "text 123";

    int num1 = atoi(str1); // 转换成功，结果为 12345
    int num2 = atoi(str2); // 转换成功，结果为 42
    int num3 = atoi(str3); // 转换成功，结果为 -5678
    int num4 = atoi(str4); // 转换失败，结果未定义（一般为 0）

    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);
    printf("num3 = %d\n", num3);
    printf("num4 = %d\n", num4);

    return 0;
}

