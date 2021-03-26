# Linux开启关机命令

### shutdown 命令
+ `shutdown [选项] 时间`
    + -c 取消前一个关机命令
    + -h 关机
    + -r 重启
+ `shutdown -r 18:00 &`定时于18:00重启,将该命令放入后台,当前可以继续操作

### 其他关机命令，不推荐使用
+ halt
+ poweroff
+ init 0
+ reboot(可以选用)
+ init 6

### 系统运行级别
+ 0 关机
+ 1 单用户
+ 2 不完全多用户,不含NFS服务
+ 3 完全多用户
+ 4 未分配
+ 5 图形界面
+ 6 重启

### 查看当前级别
+ `runlevel`查看系统运行级别
+ `cat /etc/inittab`修改系统默认运行级别`id:3:initdefault`

### 退出登录
+ `logout`正确退出用户