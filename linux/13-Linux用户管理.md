# Linux用户管理
### 用户和用户组
+ 用户(使用操作系统的人)
+ 用户组(具有相同系统权限的一组用户)
+ /etc/group 存放当前系统中用户组的信息

|Group:  |x:           |123:    |abc,def,xyz    |
|--------|-------------|--------|---------------|
|组名称: |组密码占位符:|组编号: |组中用户名列表 |

+ /etc/gshadow 存放当前系统中用户组的密码信息

|Group:  |*:     |:        |abc,def,xyz    |
|--------|-------|---------|---------------|
|组名称: |组密码:|组管理者:|组中用户名列表 |


+ /etc/passwd 存放当前系统中所有的用户信息

|user :  |x:         |123:     |456:       |xxxxxxxx:    |/home/user:|/bin/bash|
|--------|-----------|---------|-----------|-------------|-----------|---------|
|用户名: |密码占位符:|用户编号:|用户组编号:|用户注释信息:|用户主目录:|shell类型|

+ /etc/shadow 存放当前系统中所有的用户的密码信息

### 创建用户组
+ 可以在`/etc/group`下查看
+ 创建用户组`groupadd <groupName>`
+ 修改组名`groupmod -n <newGroupName> <oldGroupName>`
+ 修改组名的编号`groupmod -g <groupNumber> <groupName>`
+ 创建用户组并指定编号`groupadd -g <groupNumber> <groupName>`
+ 删除用户组`groupdel <groupName>`

### 创建用户
+ 首先创建用户组`sell`
+ 创建用户`useradd -g sell <username>` 
+ 给用户创建文件夹`useradd -d /user/xxx <username>`,如果没有指定创建文件夹,那么系统将会自动创建一个与用户名相同的文件夹
+ 给用户添加备注`usermod -c <备注内容> <username>`
+ 切换用户组`usermod -g <oldGroup> <newGroup>`
+ 删除用户`userdel <username>`(添加-r参数，同时删除文件夹)
+ 禁止root用户以外的普通用户登录服务器，在/etc目录下创建一个nologin的文件夹,然后输入`touch /etc/nologgin`

### 用户和用户组的进阶
+ 锁定用户`passwd -l <username>`
+ 解锁用户`passwd -u <username>`
+ 用户可以无密码登录`passwd -d <username>`

### 主要组和附属组
+ 同一个用户可以同时属于多个组
    + 一个主要组
    + 多个附属组
+ 把用户添加到附属组`gpasswd -a <username> <Group>`

### 用户管理其他命令
+ 切换到root用户`su <不过一般需要密码>`
+ 切换用户身份`su <username>`也需要密码
+ `whoami`用户是谁
+ `id <username>`显示用户的信息，包括用户编号，用户名
+ `groups <username>`显示用户所在的组
+ `cnfn <username>`设置用户资料，依次输入资料
+ `finger <username>`显示用户的详细资料

















