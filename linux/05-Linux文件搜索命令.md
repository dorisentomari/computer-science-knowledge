# 文件搜索命令

### 文件搜索命令locate
+ `locate <filename>`只能搜索文件名
+ `locate`在后台数据库中按照文件名搜索,搜索速度更快
+ `/var/lib/mlocate`，在#locate命令所搜索的后台数据库
+ `updatedb`更新数据库
+ 如果使用不了,需要进行安装`yum install mlocate`
+ /etc/updatedb.conf配置文件
    + 这个配置文件一共四个命令,第一个命令如果为no,则表示下边的三条命令全都不生效`PRUNE_BIND_MOUNTS="yes"`
    + 开启搜索限制 PRUNEFS=
    + 搜索时,不搜索的文件系统 PRUNENAMES=
    + 搜索时,不搜索的文件路径 PRUNEPATHS=

### 命令搜索命令whereis与which
+ whereis <命令名>
    + 只能查看系统命令,不能查看自定义命令和文件
    + 搜索命令所在路径以及帮助文档所在位置
    + `-b` 只查找可执行文件
    + `-m` 只查找帮助文档

+ which <命令名>
    + 可以看到命令的别名

### 环境变量`$PATH`
+ 系统搜索命令的路径
+ `echo $PATH`,显示环境变量位置

### 文件搜索命令find
##### find [搜索范围] [搜索条件]
+  find / -name install.log
    + 避免大范围索索,会非常耗费系统资源
    + find是在系统当中搜索符合条件的文件名,如果需要匹配,使用通配符匹配,通配符是完全匹配
+ * 匹配任意字符`find / -name "install.log*"`
+ ? 匹配任意一个字符`find / -name "a?"`
+ [] 匹配任意一个中括号内的字符`find / -name "a[bc]"`
+ `find /root -iname install.log`不区分大小写
+ `find /root -user root`按照所有者搜索
+ `find /root -nouser`查找没有所有者的文件
+ `find /var/log/ -mtime +10`查找10天修改的文件
    + -10 10天内修改文件
    + 10 10天当天修改的文件
    + +10 10天前修改的文件
    + atime 文件访问的时间
    + ctime 改变文件属性
    + mtime 修改文件内容
+ `find . -size 25k`查找大小为25k的文件
    + -25k 小于25k的文件
    + 25k 等于25k的文件
    + +25k 大于25k的文件
+ `find . -inum 264255`查找i节点时254255的文件
+ `find /etc -size +25k -a -size -50k`查找etc目录下大于20k且小于50k的文件
    + -a and 逻辑与,两个条件都满足
    + -o or 逻辑或,两个条件满足一个即可
+ `find /etc -size +20k -a -size -50k -exec ls -lh {} \;`
    + 查找etc目录下,大于20k且小于50k的文件,并显示详细信息
    + -exec/-ok命令{}\;对搜索结果执行操作

### 字符串搜索命令grep
+ grep [选项] 字符串 文件名
+ 在文件中匹配符合条件的字符串,包含匹配
+ -i 忽略大小写
+ -v 不包含指定字符串


### find命令与grep命令的区别
+ find（搜文件名）:是完全匹配,结果和搜索的文件是一样的.若想模糊匹配,可以使用通配符
+ grep（搜文件中的字符串）:是包含匹配,搜索结果为包含搜索的字符串的所有文件,并非一个我们指定的具体文件。