创建libft_creator.sh

第一步：
将所有源文件(C文件)编译为目标文件
gcc -c *.c 
假如目录里面有file1.c file2.c 这两个源文件，那么执行上面的操作会生成file1.o 和 file2.o 这两个目标文件

第二步：
将新创建的两个目标文件放到libft.a静态库里面
ar rc libft.a *.o
ar = 创建或生成一个静态库文件libft.a, 将所有目标文件打包进去
选项 r 替换库中已有的目标文件，或者添加新的目标文件
选项 c 创建库 如果库文件还不存在

第三步：
ranlib libft.a
对libft.a静态库进行索引操作。
这个命令会生成一个索引表，供链接器快速查找静态库中的符号。
重要性: 某些系统可能需要明确地运行 ranlib，以确保静态库可以被正确使用。

输入nm libft.a 来查看静态库中的符号表:

ft_putchar.o:
0000000000000000 T ft_putchar
                 U write

ft_putstr.o:
0000000000000000 T ft_putstr
                 U write

ft_strcmp.o:
0000000000000000 T ft_strcmp

ft_strlen.o:
0000000000000000 T ft_strlen

ft_swap.o:
0000000000000000 T ft_swap
我们可以发现所有的目标文件都已经存档在libft.a里面了

第四步：
rm *.o
功能: 删除当前目录中的所有目标文件（.o 文件），以清理临时文件。
原因: 目标文件已经被包含在静态库 libft.a 中，因此可以安全地删除它们，保持目录整洁。

如何使用静态库？
如果我们调用静态库当中的某一个函数来创建一个main函数新源文件
#include "/home/yan/Code_C/c08/ex00/ft.h"

int     main(void)
{
        ft_putstr("Hello Lilou");
        return (0);
}

我们可以直接使用静态库来编译main函数源文件
gcc main.c -L. -lft
这样我们可以直接生成a.out执行文件
注意：
由于静态库名称是libft.a，在使用链接静态库-l时 要去掉lib前缀和.a后缀，否则系统报错无法成功编译文件
PS: include 头文件还是必须要加在所有的源文件当中，无论是创造这个函数的源文件还是需要调用这个函数的新建源文件
