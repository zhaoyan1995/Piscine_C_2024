Makefile的作用主要是用来批量编译文件的
这个题的目的主要是为了创建一些编译所用的基本规则

我们创建一下变量来编写编译文件的程序

LIB NAME 指代静态库的名称

SRC PATH 指代源文件的路径，因为他们都在相对路径./srcs/里面
SRC 代表源文件列表，这里面我们列出所有相对路径里面的源文件名称

OBJ 代表相对路径里面的相关目标文件，其实在运行make命令之前我们并没有创造目标文件，但我们先罗列出来，没有关系

HEADER 代表头文件的相对路径，我们编译源文件到目标文件的时候要使用

"all :" 表示在命令行输入make 或者make all 默认所执行的任务

Makefile里面指定规则都是这样的：
Target file ： Dependency file 
                Instructions
引号左边是要生成的文件，引号右边是依赖文件，意思是说为了生成要生成的文件需要依靠Dependency file，之后另起一行是命令行中需要执行的语句

$(LIB_NAME): $(OBJ)
        ar rcs $@ $^

上面这两行代码表示要生成静态库LIB NAME 我需要依赖于目标文件，$@代表要生成的文件 $^代表所有依赖文件，因为通常有多个目标文件的时候才需要生成静态库将目标文件都存储在静态库里面，注意顺序不要写错了

$(SRC_PATH)%.o : $(SRC_PATH)%.c
        gcc -c $(FLAG) -I$(HEADER) $< -o $@
上面这两行是为了把每一个源文件编译成目标文件，我们希望源文件和目标文件都存储在指定的相对路径里面，所以我们在引号前和引号后的加了相对路径变量%

%是一个模式匹配符，用于在模式规则中匹配文件名的某一部分 它通常在模式规则中使用
在上面的代码中%代表可以匹配任何字符，在这个例子中 %.c %.o 都会匹配同名的.o 和 .c文件
"-I$(HEADER)" 表示根据头文件路径编译源文件成目标文件，缺失这个指令的话，系统会找不到头文件，编译会失败，如果不想加这个指令，可以在每一个源文件里面加上源文件的相对路径或者绝对路径，但是-I$(HEADER)是最灵活的操作方法
我们把依赖文件写在header路径之后 也就是$< 它代表第一个依赖文件 这里我们的每一个要生成的文件只需要依赖一个源文件即可 所以我们可以写$< 也是唯一的一个依赖文件
我们将要生成的文件写在最后面 即$@
注意 ：目标文件和依赖文件的位置不要写错

clean:
        rm -f $(OBJ)
这个操作是用来删除所有.o结尾的文件，使用f选项是force操作，假如已经不存在.o结尾的文件，那么使用f可以避免报错，保证程序可以继续进行下去

fclean：clean
        rm -f $(LIB_NAME)
这个操作不仅要将目标文件删掉，并且还有删掉静态库，clean规则必须在fclean之前执行，这样输入make fclean的时候就可以同时删掉所有.o文件并且删除静态库
注意：
clean不可以写在下一行，因为linux没有clean这个语句

re ： fclean all
这个操作会删掉静态库和所有.o结尾的文件，并且重新建立静态库和.o结尾的文件 re = rebuild，这个操作用于更新静态库
这个操作不仅要将目标文件删掉，并且还有删掉静态库，clean规则必须在fclean之前执行，这样输入make fclean的时候就可以同时删掉所有.o文件并且删除静态库
注意：
clean不可以写在下一行，因为linux没有clean这个语句

re ： fclean all
这个操作会删掉静态库和所有.o结尾的文件，并且重新建立静态库和.o结尾的文件 re = rebuild，这个操作用于更新静态库


