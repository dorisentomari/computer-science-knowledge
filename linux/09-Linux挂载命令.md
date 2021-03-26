# Linux其他常用命令
**了解即可，不要修改**

[TOC]

# 挂载命令(分配盘符)(用户登录查看和用户交互命令)
### 查询与自动挂载
+ `mount`查询系统中已经挂载的设备
+ `mount -a`依据配置文件/etc/fstab的内容,自动挂载

### 挂载命令格式
+ `mount [-t 文件系统] [-o 特殊选项] 设备文件名 挂载点`
+ -t 文件系统:加入文件系统类型来指定挂载的类型,可以ext3,ext4,iso9660等文件系统
+ -o 特殊选项：可以指定挂载的额外选项

### 书写写脚本
+ `vi hello.sh`
```
#!/bin/bash
echo "hello linux!"
```

+ 赋予权限`chmod 755 hello.sh`
+ 执行脚本`./hello.sh`

### 挂载光盘
+ 建立光盘,载入一个iso镜像光盘
+ `mkdir /mnt/cdrom`建立挂载点
+ `mount -t iso9660 /dev/cdrom/mnt/cdrom`挂载光盘
+ `mount /dev/sr0/mnt/cdrom`

### 卸载命令(一定要卸载)
+ `umount 设备名/挂载点`
+ `umount /mnt/cdrom`

### 挂载U盘
+ `mount -t vfat /dev/sdb1/mnt/usb/`(vfat指定支持fat格式)
+ 注意:Linux默认不支持NTFS文件系统

# 用户登录查看命令
### `w`命令
+ USER:登录的用户名
+ TTY:登录终端
+ FROM:从哪个IP地址登录
+ LOGIN:登录时间
+ IDLE:用户闲置时间
+ JCPU:和该终端连接的酥油进程占用的时间，这个事件不包括过去的后台作业事件，但却包括当前正在运行的后台作业所占用的的时间
+ PCPU:当前进程所占用的时间
+ WHAT:当前正在运行的命令

### `who`命令
+ 用户名
+ 登录终端
+ 登录时间(登录来源IP地址)

### `last`命令
+ 默认读取/var/log/wtmp文件数据
+ 用户名
+ 登录终端
+ 登录IP
+ 登录时间
+ 退出时间(在线时间)

### `lastlog`命令
+ 默认是读取/var/log/lastlog文件内容
+ 用户名
+ 登录终端
+ 登录IP
+ 最后一次登录时间