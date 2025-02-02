cat 函数的特点：
cat filename1 filename2
打印filename1 和filename2文件的内容
cat nonexistingfile
如果nonexistingfile是一个完全不存在的文件那么这个函数会返回一下报错信息
cat: nonexistingfile : No such a file or directory
如果输入cat，然后另起一行书写，cat函数会复制粘贴输入的字符
例子：
cat
Hello
Hello
dfsdf
dfsdf
一直到按下Ctrl C才会终止程序

所以我们根据cat的这三种可能性仿写cat函数。

I. 第一种情况当输入cat filename并且filename存在，可读的情况下。
open函数
声明一个int变量file，将他带入open函数当中，open函数源于<fcntl.h>，查询man 2 open 即可知道它所属的header文件。
file = open("filename",O_RDONLY) 用于打开只可读文件，如果这个filename这个文件名存在，并且在当前目录的话，那么file的返回值就是一个正整数，如果不存在该文件那么file等于－1。
PS：这里如果open是第一次调用的话，那么file的值(即文件描述符是3)，因为文件描述符0代表STDIN，就是标准输入，文件描述符1表达STDOUT，就是标准输出。然后文件描述符2表达STDERROR，即标准错误。所以当open被第一次调用他会调用可用的最小的文件描述符，即3。如果第二次调用那么file就变成了4，然后第三次调用变成5，以此类推。所以当调用open之后，一定记得调用close，否则这个文件就会一直占用这个文件描述符，导致文件资料泄露。

read函数
当file是一个不等于－1的数的时候，就可以带入到read函数当中去,此函数位于<unistd.h>中。声明一个int变量byte_size, 一个char buffer[30000]，byte_size = read(file, buffer, sizeof(buffer) -1), 这个函数是用来读取file文件里面的内容，byte_size表示读取到的字节数，每一个读取到的字节都会一个一个存储在buffer里面，sizeof(buffer) - 1 代表可供读取的容量最大是都少，这里－1是为了考虑最极端的情况，如果文件字节数超过29999的话，那么一定留下buffer的最后一位用来填充'\0'。
之后buffer[byte_size] = '\0', 通过加终止符的方式来防止打印的时候出现未定义事件。

当file被读取后，使用ft_putstr_2(buffer, byte_size)来读取buffer中的内容，里面有while循环控制write函数一个一个写出buffer中的字符，直到写到第byte_size个为止，这里为什么没有用常规的 while(*buffer != '\0'),因为有一些文件可能会包含'\0'终止符，但是在终止符之后还有内容所以不能以不等于终止符'\0'为条件来终止循环。

最后当打印函数完成执行记得使用close函数释放掉文件描述符给下一个文件使用。

由于cat 其实可以打印多个文件，这个时候argv[i]里面要有i++,直到i的值达到argc －1。


II. 第二种情况当输入cat filename但是filename不存在
报错信息可以自己编译，但同时也可以调用在string.h当中的strerror(errno)函数，errno参数可以在errno.h当中寻找，这个头部文件包含了所有错误码，每个错误码就是一个宏，每一个宏代表一个报错信息，当open的返回值是－1的时候，系统底层检测到这个错误，并把它链接到errno的相关错误码中，即包含"No such file or directory"的宏当中，当调用此strerror(errno)，并将他赋值给一个字符串指针，他就可以实现打印。

III. 第三种情况当输入cat但是没有任何argv紧随其后，但是我们按enter键另起一行写入一段文字时
这种情况下argc 是等于1的，之后另起一行写入的文字不是argv，而是标准输入，即STDIN, 这种情况下，我们可以另外写一个专门用来打印标准输入的分函数，不需要调用open函数，调用read函数来读取标准输入，声明byte_size这个int变量，用read函数给byte_size赋值，创建char buffer size固定为30000 和第一种情况一样，只是没有使用open函数,之后我们写byte_size = read(0, buffer, sizeof(buffer) - 1), buffer[30000] ='\0', 然后通过write(0, buffer, byte_size)打印处刚刚读取的标准输入, 通过无限循环的方式while(1)，不停在while循环当中给byte_size赋值, 直到用户按Ctrl C才终止程序。

PS: 为什么无限循环中只会读取一次STDIN之后仅复制一次标准输入呢?
只复制一次的原因：当你输入数据后按 Enter，read 会读取一次，并使用write函数打印出来。
无限循环未发生的原因：read 会阻塞等待新的输入。如果输入结束（EOF），read 返回 0，但程序不会退出，仍然在等待新的输入。
 
