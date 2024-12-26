创建header头文件后，内部包含数个函数，如何通过调用header头文件来调用这些函数呢

例如：
/home/yan/Code_C/c00/ex00/ft_putchar.c
void ft_putchar(char c);


在ft.h里面有声明函数void ft_putchar(char c)
ft.h 在/home/yan/Code_C/c08/ex00/ft.h

那么在ft_putchar.c源文件开头的位置中就必须加include "/home/yan/Code_C/c08/ex00/ft.h", 并且在源文件中禁用main函数

在需要调用ft_putchar函数的新c文件中也必须加include "/home/yan/Code_C/c08/ex00/ft.h"

新c文件建立好后不可直接编译
操作如下：
假设新c文件名称是 new_file.c 
需要在当地文件夹转换成目标文件 gcc -c new_file.c -o new_file.o
new_file.o即为目标文件
同样的ft_putchar.c文件也要在它所在的文件夹进行转换
gcc -c ft_putchar.c -o ft_putchar.o
最后在new_file.c文件夹下编译给两个目标文件创建链接：
gcc new_file.o /home/yan/Code_C/c00/ft_putchar.o 
然后执行a.out文件

如果新文件要调用多个ft.h中的函数的话在创建链接是要把新文件目标文件和所有调用函数的目标文件全部写下来
例如
gcc test.o /home/yan/Code_C/c01/ex02/ft_swap.o /home/yan/Code_C/c00/ex00/ft_putchar.o
test.o需要调用ft_swap.c 和 ft_putchar.c 这两个函数，并且他们都在ft头部文件中被声明.h头部文件中被声明
