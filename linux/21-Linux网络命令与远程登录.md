# Linux网络命令
### 网络环境查看命令
+ `ifconfig`
+ `ifdown 网卡设备名`禁用该网卡设备
+ `ifup 网卡设备名`启用该网卡设备
+ 查询网络状态`netstat 选项`
    + `-t`:列出TCP协议端口
    + `-u`:列出UDP协议端口
    + `-n`:不适用域名与服务名,而是用IP地址和端口号
    + `-l`:仅列出在监听状态网络服务
    + `-a`:列出所有的网络连接
    + `netstat -tuln`查看所有的服务端口号
+ `netstat -an | grep ESTABLISHED | wc -l`查看当前登录用户数
+ `netstat -rn`
    + `-r`列出路由列表,与`-route -n`一致
+ `route`命令
    + `route -n`查看路由列表(可以看到网关)
    + `route add default gw 192.168.x.x`临时设定网关
+ 域名解析命令
    + `nslookup [主机名或IP]`进行域名或IP地址解析
```
$ nslookup
>server
```

### 网络测试命令
##### `ping`命令
+ `ping [选项] ip或域名`:探测指定IP或域名的网络状况
+ `-c 次数`:指定ping包的次数

##### `telnet`命令(明文传输,不安全,可以用来探测端口)
+ `telnet [域名或IP] [端口]`远程管理与端口探测命令
+ `telnet 192.168.0.0 80`

##### `traceroute`
+ `traceroute [选项] IP或域名`路由跟踪命令
+ `-n` 使用IP,不使用域名,速度更快

##### `wget`命令
+ `wget http://xxx.com`下载命令

##### `tcpdump`抓包命令
+ `tcpdump -i eth0 -nnX port 21`
+ `-i`:指定网卡接口
+ `-nn`:将数据包中的域名与服务转为IP和端口
+ `-X`:以十六进制和ASCII码显示数据包内容
+ `port`:指定监听的端口

# Linux远程登录
[TOC]

**对称加密算法**
+ 采用单钥密码系统的加密方法,同一个密钥可以同时用作信息的加密和解密,这种加密方式称为对称加密,也成为单密钥加密.

**非对称加密算法**
+ 非对称加算法(asymmetric ceyptographic algorithm)又名"公开密钥加密算法",非对称加密算法需要两个密钥:公开密钥(publickey)和私有密钥(privatekey)

### SSH协议原理
+ SSH安全外壳协议
+ `SSH 用户名@ip`:远程管理指定Linux服务器
+ `scp [-r] 用户名@ip:文件路径 本地路径`:下载文件
+ `scp 本地文件 用户名@ip:上传路径`:上传文件