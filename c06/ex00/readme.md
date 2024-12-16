char *argv[] :
在函数 main 中，char *argv[] 表示一个指针数组，数组中的每个元素都是一个指向字符（字符串）的指针。
通常，argv 是由系统在程序启动时初始化的，用于存储命令行参数。

具体内容为：
argv[0]：指向程序名（或者程序路径）字符串。
argv[1]：指向第一个命令行参数。
argv[2]：指向第二个命令行参数。
...
argv[argc]：始终为 NULL，标记数组的结束。

例如，执行命令：
./program arg1 arg2
系统会将以下值填充到 argv 中：
argv[0] = "./program";
argv[1] = "arg1";
argv[2] = "arg2";
argv[3] = NULL;

在上面这个例子里argc = 3

int main(int argc, char *argv[])
或等价的：
int main(int argc, char **argv)

无命令行参数的定义：
int main(void)

为什么通常需要 int argc？
1. argc 表示命令行参数的数量：
- argc（argument count）用于告诉程序命令行参数的个数，包括程序名称本身。
- argv 是一个指针数组，用于存储命令行参数，但你无法通过仅仅使用 argv 判断数组的大小。没有 argc，程序无法知道 argv 中有多少有效元素。

2. 访问 argv 必须保证安全：
如果没有 argc 参数，就无法确定 argv 的边界，直接使用 argv 会有潜在的越界风险。(Segmentation fault (core dumped)).



