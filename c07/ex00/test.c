#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("请输入数组大小: ");
    scanf("%d", &n);

    int *p;   
    if (p == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }

    // 初始化数组
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
    }

    // 输出数组内容
    printf("数组内容: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    return 0;
}

