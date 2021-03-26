# Linux软件安装
# 软件包管理简介
### 软件包分类
+ 源码包(脚本安装包)
+ 二进制包(RPM包,系统默认包)
+ 编译(语言编译成01数字)
+ 反编译(容易造成代码损失)

### 源码包的优点
+ 开源,如果有足够的能力,可以修改源代码
+ 可以自由选择所需的功能
+ 软件是编译安装,所以更加合适自己的系统,更加稳定更加高效
+ 卸载方便

### 源码包的缺点
+ 安装过程步骤较多,尤其安装较大的软件集合时(LAMP环境搭建),容易出现拼写错误
+ 编译过程时间较长,安装比二进制安装时间长
+ 编译安装一旦报错,新手很难解决

### RPM包和脚本安装包
##### 二进制包的优点
+ 包管理系统简单,只通过几个命令就可以实现包的安装,升级,查询和卸载
+ 安装速度比源码包安装的快

##### 二进制包的缺点
+ 经过编译,不再可以看到源代码
+ 功能选择不如源码包灵活
+ 依赖性

##### 脚本安装包
+ 所谓的脚本安装包,就是把复杂的软件包装过程写成了程序脚本,初学者可以执行程序脚本直线一键安装.但是实际安装的还是源码包或者二进制包
+ 优点:安装简单快捷
+ 缺点:完全丧失额自定义性

# rpm命令管理
### rpm包
##### rpm包命名规则
+ `httpd-2.2.12-15.el6.centos.1.i686.rpm`
+ `httpd`软件包名
+ `2.2.12`软件版本
+ `15`软件发布的次数
+ `el.centos`适合的Linux平台
+ `i686`适合的硬件平台
+ `rpm`rpm包扩展名

##### rpm包依赖性
+ 树形依赖:a->b->c
+ 环形依赖:a->b->c->a(放在同一条命令里)
+ 模块依赖:模块依赖查询网站`www.rpmfind.net`

### 安装命令
##### 包全名与包名
+ 包全名:操作的包是没有安装的软件包时,使用包全名,而且注意路径
+ 包名:操作已经安装的软件包时,使用包名,是搜索`/var/lib/rpm/`中的数据库

##### rpm安装
+ `rpm -ivh 包全名`
+ `-i(install)`:安装
+ `-v(verbose)`:显示详细信息
+ `-h(hash)`:显示进度
+ `--nodeps`:不检测依赖性(禁止使用)

### 升级与卸载
##### 升级
+ `rpm -Uvh 包全名`
+ `-U(upgrade)`升级

##### 卸载
+ `rpm -e 包名`
+ 卸载也有依赖性
+ `--nodeps` 不检测依赖性

### **rpm包查询**
##### 查询是否安装
+ `rpm -q 包名`查询包是否安装
+ `rpm -qa`查询所有安装过的包
+ `rpm -qa | grep httpd`

##### 查询软件包的详细信息
+ `rpm -qi 包名`
+ `-i`:查询软件信息(information)
+ `-p`:查询未安装包信息(package)

##### 查询包中文件安装位置
+ `rpm -ql 包名`
+ `-l`:列表(list)
+ `-p`:查询未安装包信息(package)

##### rpm包默认安装位置
+ `/etc/`:配置文件安装目录
+ `/usr/bin/`:可执行的命令安装目录
+ `/usr/lib/`:程序锁使用的函数库保存位置
+ `/usr/share/doc/`:基本的软件使用手册保存位置
+ `/usr/share/man`:帮助文件保存位置

##### 查询系统文件属于哪个rpm包
+ `rpm -qf 系统文件名`
+ `-f`:查询系统文件属于哪个软件包(file)

##### 查询软件包的依赖性
+ `rpm -qR 包名`
+ `-R`:查询软件包的依赖性(requires)
+ `-p`:查询未安装包信息(package)

### rpm包校验
##### rpm校验已安装的包名
+ `rpm -V 已安装的包名`
+ `-V`:校验指定rpm包中的文件(verify)
+ 验证内容中的8个信息的具体内容
    + `S`:文件大小是否改变
    + `M`:文件的类型或文件的权限(rwx)是否被改变
    + `5`:文件的MD5校验和是否改变(可以看成文件内容能够是否改变)
    + `D`:设备的主从代码是否改变
    + `L`:文件路径是否改变
    + `U`:文件的属主(所有者)是否改变
    + `G`:文件的属组是否改变
    + `T`:文件的修改时间是否改变
+ 文件类型
    + `c`:配置文件(config file)
    + `d`:普通文件(documentation)
    + `g`:鬼文件(ghost file),很少见,就是该文件不应该被这个rpm包包含
    + `L`:授权文件(license file)
    + `r`:描述文件(read me)

##### rpm包中文件提取
+ `rpm2cpio 包全名 | cpio -idv.文件绝对路径`
    + `rpm2cpio`将rpm包转换为cpio格式的文件
    + `cpio`是一个标准工具,用户创建软件档案和从档案文件中提取文件
+ `cpio 选项 < [文件|设备]`
    + `-i`:copy-in模式,还原
    + `-d`:还原时自动新建目录
    + `-v`:显示还原过程

# yum在线管理
+ 好处:将所有软件包放到官方服务器上,当进行yum在线安装时,可以自动解决依赖性问题
+ redhat的yum在线安装需要付费

### yum源文件
+ `/etc/yum.repos.d/CentOS-Base.repo`
+ `[base]`:容器名称,一定要放在[]中
+ `name`:容器说明,可以自己随便写
+ `mirrorlist`:镜像站点,这个可以注释掉
+ `baseurl`:yum源服务器的地址,默认是CentOS官方的yum源服务器,是可以使用的,也可以修改为其他的
+ `enabled`:此容器是否生效,如果不写或写成enable=1都是生效的,如果写成enable=0就是不生效
+ `gpgcheck`:如果是1是指rpm的数字证书生效,如果是0则不生效
+ `gpgkey`:数字证书的公钥文件保存位置,不需要修改

### yum在线安装
##### 挂载光盘
+ `mkdir /mnt/cdrom`建立挂载点
+ `mount /dev/cdrom /mnt/cdrom/`挂载光盘
+ `cd /etc/yum.repos.d/`进入yum源目录
+ `mv CentOS-Base.repo CentOS-Base.repo.bak`修改yum源，使其无效
+ 使光盘yum源生效(CentOS-Media.repo)
```
[c6-media]
name=CentOS-$releasever - Media
baseurl=file:///mnt/cdrom
#        file:///media/cdrom/
#        file:///media/cdrecorder/
gpgcheck=1
enabled=1
gpgkey=file:///etc/pki/rpm-gpg/RPM-GPG-KEY-CentOS-6
```

##### yum命令
+ `yum list`查询所有可用的软件包列表
+ `yum search 关键字`搜索服务器上所有和关键字相关的包
+ `yum -y install 包名`安装包(yum安装只需要包名,不需要包全名)
    + `install`安装
    + `-y`自动回答yes
+ `yum -y update 包名`升级更新
    + `update`升级
    + `-y`自动回答yes
+ `yum -y remove 包名`
    + `remove`卸载
    + 服务器使用最小化安装,用什么软件安装什么软件,尽量不卸载
+ `yum软件组管理命令`
    + `yum grouplist`列出所有可用的软件组列表
    + `yum groupinstall 软件组名`安装指定软件组,组名可以由grouplist查询出来
    + `yum groupmove 软件组名`卸载指定软件组
    + `LANG=us_EN`切换成英文
    + `LANG=zh_CN.utf8`切换成中文

# 源码包管理
### 区别
+ 安装前的区别:概念上的区别
+ 安装后的区别:位置上的区别

##### 安装位置不同带来的影响
+ rpm包安装的服务可以使用系统服务管理命令(service)来管理
+ rpm包安装的apache的启动方法是`/etc/rc.d/init.d/httpd start`,`service httpd start`

##### 源码包安装位置
+ 安装在指定位置当中,一般是`/usr/local/软件名/`
+ 源码包安装的服务不能被服务管理命令管理,因为没有安装到默认的路径中，所以只能使用绝对路径进行服务的管理`/usr/local/apache2/bin/apachectl start`

##### 源码包安装准备
+ 下载C语言编译器`yum -y install gcc`,`http://mirror.bit.edu.cn/apache/httpd/`
+ 源码包保存位置:`/usr/local/src`
+ 软件安装位置:`/sur/local/`
+ 如何确定安装过程报错
    + 安装过程停止
    + 并且出现`error`,`warning`,`no`提示

##### 源码包安装过程
+ 下载源码包
+ 解压缩下载的源码包
+ 进入解压缩目录
+ `./configure`软件配置与检查
    + `./configure --prefix=/usr/local/apache`
    + 解压后的文件夹里边有一个`INSTALL`文件,里边有说明文件
    + 定义需要的功能选项
    + 检测系统环境是否符合安装要求
    + 把定义好的功能选项和检测系统环境的信息都写入Makefile文件,用于后续的编辑
+ `make`编译
    + `make clean`如果报错,执行`make clean`,从头安装
+ `make install`编译安装
+ `/usr/local/apache/bin/apachectl start`启动服务

##### 源码包的卸载
+ 不需要卸载命令,直接删除安装目录即可,不会遗留任何垃圾文件

### rpm包安装位置是默认位置(即作者认为应该安装在哪个文件下)

# 脚本安装包
+ 简单便捷,自动安装

### 强大的Nginx服务器
+ Nginx是一款轻量级的web服务器/反向代理服务器及电子邮件(IMAP/POP3)代理服务器,由俄国公司在2004年发布.
+ Nginx在反向代理,Review规则,稳定性,静态文件处理,内存消耗等方便,表现出了很强的优势,选用Nginx取代传统的apache服务器,将会得到很好的性能提升.

##### 准备工作
+ 关闭rpm包安装和httpd和MySQL
    + `rm -rf /usr/local/apache`
    + `service mysqld stop`
+ 保证yum源正常使用
    + `yum list`
+ 管理SELinux和防火墙
    + 太复杂，所以直接永久关闭
    + `/etc/selinux/config`
    + `SELINUX=enforcing`改为`SELINUX=disabled`
    + 重启计算机

##### install.sh脚本分析
+ 优点:简单快速方便
+ 缺点:
    + 不能定义安装软件的版本
    + 不能定义所需要的软件功能
    + 源码包的优势丧失

##### 安装lnmp
+ 网站:`https://lnmp.org/install.html`
+ wget -c http://soft.vpser.net/lnmp/lnmp1.4.tar.gz && tar zxf lnmp1.4.tar.gz && cd lnmp1.4 && ./install.sh lnmp
+ 一条命令安装
+ 中间会有一个`php-fpm`阻断，杀死这条进程即可
+ `ps aux`
+ `pkill -9 <pid>`
+ 重新启动`php-fpm`，`/etc/rc.d/init.d/php-fpm start`
