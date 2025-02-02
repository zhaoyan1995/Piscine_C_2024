如何使用ulimit来限制新建文件的大小：
以下操作用于显示所有默认的当前限制，每一次打开LINUX都是这个默认设置。
ulimit -a
real-time non-blocking time  (microseconds, -R) unlimited
core file size              (blocks, -c) 0
data seg size               (kbytes, -d) unlimited
scheduling priority                 (-e) 0
file size                   (blocks, -f) unlimited
pending signals                     (-i) 11768
max locked memory           (kbytes, -l) 65536
max memory size             (kbytes, -m) unlimited
open files                          (-n) 1024
pipe size                (512 bytes, -p) 8
POSIX message queues         (bytes, -q) 819200
real-time priority                  (-r) 0
stack size                  (kbytes, -s) 8192
cpu time                   (seconds, -t) unlimited
max user processes                  (-u) 11768
virtual memory              (kbytes, -v) unlimited
file locks                          (-x) unlimited

ulimit -f用来限制新建文件的大小
ulimit -f 1 限制的新建文件的大小是512个字节, 如果我们需要限制新建的文件在30ko之内，即30*1024个字节之内, 所以我们限制的选项是60，因为 512 * 60 = 30 * 1024 在这个字节之内，在这个限制之外，系统会阻止你创建这个文件，这个限制在关闭当前对话框之后就会自动恢复默认值，即unlimited。也可以通过ulimite -f unlimited来取消当前对话框限制。
