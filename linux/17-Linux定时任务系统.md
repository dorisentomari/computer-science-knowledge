# Linux定时任务系统
### at一次性执行
##### 确定at安装
+ `chkconfig --list |grep atd`at服务是否安装
+ `service atd status`查看atd状态
+ `service atd restart`at服务启动
+ `CentOS7`之后,`chkconfig`命令已经被`systemctl`命令取代,`chkconfig --list | grep atd` == `systemctl  list-unit-files | grep atd`,查看状态可以用`systemctl  status atd.service`


##### at的访问控制
+ 如果系统中有`/etc/at.allow`文件，那么只有写入`/etc/at.allow`文件(白名单)中的用户可以使用at命令(`/etc/at.deny`文件会被忽略)
+ 如果系统中没有`/etc/at.allow`文件,只有`/etc/at.deny`文件，那么写入`/etc/at.deny`文件(黑名单)中的用户不能使用at命令.(对root不起作用)
+ 如果系统中的这两个文件都不存在,那么只有root用户可以使用at命令

##### `at命令`
+ `at [选项] 时间`
+ `-m`:当at工作完成后，无论是否命令有输出，都有email通知执行at命令的用户
+ `-c 工作号`:显示该at工作的实际内容
+ `atq`查询定时任务号
+ `atrm [工作号]`删除定时任务
+ 时间
    + HH:MM----------例如:02:30
    + HH:MM YYYY-MM-DD----------例如:02:30 2017-07-25
    + HH:MM[am|pm] [month] [date]----------例如:02:30 June 25
    + HH:MM[am|pm] + [minutes|hours|days|weeks]----------例如:now + 5 minutes

##### 例子
+ `at now +2 minutes`在两分钟后执行
+ `at > /root/hello.sh`这是执行的任务

### crontab循环定时任务
##### crond服务管理与访问控制
+ `service crond restart`
+ `chkconfig crond on`

##### 访问控制
+ 当系统中有`/etc/cron.allow`文件时,只有写入此文件的用户可以使用crontab命令,没有写入的用户不能使用crontab命令.同样如果有此文件,`/etc/cron.allow`文件的优先级更高。
+ 当系统中只有`/etc/cron.deny`文件时,则写入此文件的用户不能使用crontab命令,没有写入文件的用户可以使用crontab命令.

##### 用户的crontab设置
+ `crontab [选项]`
+ `-e`:编辑crontab定时任务
+ `-l`:查询crontab任务
+ `-r`:删除当前用户所有的crontab任务

##### `crontab -e`任务
+ 最小识别时间是分钟，最大识别是月
**前边加五个*号**
+ 第一个`*`号,每小时当中的第几分钟,0-59
+ 第二个`*`号,每天当中的第几个小时,0-23
+ 第三个`*`号,每个月当中的第几天,1-31
+ 第四个`*`号,每年当中的第几个月,1-12
+ 第五个`*`号,每周当中的星期几,0-7(0和7都代表周日)

**逗号(，)**
+ 代表不连续的时间,比如`0 8,12,16***命令`，代表在每天的8:00,12:00,16:00都执行一次命令

**`横线(-)`**
+ 代表连续的时间范围,比如`0 5 * * 1-6命令`,代表在周一到周六的5:00执行命令

**`(*/n)`**
+ 代表每隔多久执行一次,比如`*/10 * * * * 命令`,代表每隔1分钟就执行一遍命令

##### crontab注意事项
+ 六个选项都不能为空,必须填写,如果不确定使用*代替任意时间
+ crontab定时任务,最小有效时间时分钟,最大时间范围是月
+ 在定义时间时,日期和兴趣最好不要在一条定时任务中出现,因为他们都是以天作为单位,非常容易引起混乱。
+ 在定时任务中,不管是直接写命令,还是在脚本中写命令,都最好是绝对路径。

### 系统的crontab设置
+ 把需要执行的脚本拷贝到`/etc/cron.{daily,weekly,monthly}`目录中的任意一个
+ 修改`/etc/crontab`配置文件

### anacron配置
+ `/etc/anacrontab`
+ anacron是用来保证在系统关机的时候错过的定时任务,可以在系统开机之后再执行
+ anacron会使用一天,一周,一月作为检测周期
+ 在系统的`/var/spool/anacron/`目录中存在`cron.{daily,weekly,monthly}`文件,用于记录上次执行cron的时间
+ 和当前时间做比较,如果两个时间的差值超过了anacron的指定时间差值,证明有cron任务被执行
+ 在centos6以前,`/etc/cron.{daily,weekly,monthly}`这些目录会被cron调用,也会被anacron调用,容易重复调用
+ 在centos6.x中则只会被anacron调用,避免了重复执行
+ 在centos6.x中,anacron不再是服务,而是系统命令

##### cron.daily工作来说明执行过程
+ 首先读取`/var/spool/anacron/cron.daily`中的上一次anacron执行的时间
+ 和当前时间比较,如果两个时间的差值超过1天,就执行cron.daily工作
+ 执行这个工作职能在03:00-22:00之间
+ 执行工作时强制延迟5分钟,再随机延迟0-45分钟
+ 使用nice命令指定默认优先级,使用`run-parts`脚本执行`/etc/cron.daily`目录中的所有可执行的文件




