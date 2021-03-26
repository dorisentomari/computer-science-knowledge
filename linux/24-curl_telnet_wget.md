## 1. curl

Curl是一个命令行方式下传输数据的开源传输工具，支持多种协议包括：FTP,HTTP,HTTPS,IMAP,POP3,TELNET等。同样支持HTTP POST方法，PUT方法，FTP上传，cookie，用户名/密码认证，下载文件端点续传等，功能十分强大。

#### 1.1 curl <url>
+ 在命令行输出url页面的内容

#### 1.2 下载 `-o/-O`
+ `curl -o <文件名> <url>` 下载该url页面的内容，名字是指定的文件名
+ `curl -O <url>` 下载该url页面的内容，名字是默认的文件名,这个url必须有有文件名，否则不能下载

#### 1.3 上传 `-T/--upload-file`
+ 向服务器上传文件
+ `curl -T "fileName" <url>`
+ 向服务器上传多个文件文件
+ `curl -T "{fileName1, fileName2} <url>"`

#### 1.4 POST方法 `-d/--data`
+ `-d/--data`
+ `curl -d "id=1" <url>`传递一个参数
+ `curl -d "id=1" -d "name=jack" <url>`传递多个参数
+ `-data-urlencode`参数:可以自动转义特殊字符，无需人工事先转义。

#### 1.5 设置referer  `-e/--referer`
+ 直接请求某个url不能成功，需要判断referer是否正确
+ `curl -e <url>`

#### 1.6 指定User Agent  `-A/--user-agent`
+ `-A/--user-agent`伪装成指定的浏览器Chrome访问，用法：
+ `curl -A “Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1650.63 Safari/537.36” http://www.example.com`

#### 1.7 伪造cookie `-b/--cookie`
+ 指定参数和值`curl -b "name=xxx" <url>`
+ 从文件中读取`curl -b ./cookie.txt <url>`

#### 1.8 保存cookie `-c/--cookie-jar`
+ curl命令执行后保存操作时生成的cookie到文件
+ `curl -c ./cookie.txt -d username=aaa -d pwd=***** <url>`

#### 1.9 只输出响应头部信息 `-I/-head`
+ `curl -I <url>`

## 2. telnet
telnet命令通常用来远程登录。telnet程序是基于TELNET协议的远程登录客户端程序。Telnet协议是TCP/IP协议族中的一员，是Internet远程登陆服务的标准协议和主要方式。它为用户提供了在本地计算机上完成远程主机工作的 能力。在终端使用者的电脑上使用telnet程序，用它连接到服务器。终端使用者可以在telnet程序中输入命令，这些命令会在服务器上运行，就像直接在服务器的控制台上输入一样。可以在本地就能控制服务器。要开始一个 telnet会话，必须输入用户名和密码来登录服务器。Telnet是常用的远程控制Web服务器的方法。
　　但是，telnet因为采用明文传送报文，安全性不好，很多Linux服务器都不开放telnet服务，而改用更安全的ssh方式了。但仍然有很多别的系统可能采用了telnet方式来提供远程登录，因此弄清楚telnet客户端的使用方式仍是很有必要的。


#### 2.1 登录
+ `telnet <ip> <port>`


## 3. wget
wget命令用来从指定的URL下载文件。wget非常稳定，它在带宽很窄的情况下和不稳定网络中有很强的适应性，如果是由于网络的原因下载失败，wget会不断的尝试，直到整个文件下载完毕。如果是服务器打断下载过程，它会再次联到服务器上从停止的地方继续下载。这对从那些限定了链接时间的服务器上下载大文件非常有用。

#### 3.1 下载
+ `wget <url>`
+ 下载并以不同的文件名保存`wget -O <url>`
+ 限速下载`wget --limit-rate=300k <url>`
+ 断点续传`wget -c <url>`
    + 使用wget -c重新启动下载中断的文件，对于我们下载大文件时突然由于网络等原因中断非常有帮助，我们可以继续接着下载而不是重新下载一个文件。需要继续中断的下载时可以使用-c参数
+ 后台下载`wget -b <url>`
    + 可以使用`tail -f wget-log`查看下载进度
+ 伪装代理名称下载`wget --user-agent ="**" <url>`
+ 测试下载链接`wget --spider <url>`
    + 以下几种情况下使用--spider参数
    + 定时下载之前进行检查
    + 间隔检测网站是否可用 
    + 检查网站页面的死链接
+ 增加重试次数`wget --tried=40 <url>`
    + 如果网络有问题或下载一个大文件也有可能失败。wget默认重试20次连接下载文件。如果需要，你可以使用--tries增加重试次数
+ 下载多个文件`wget i fulelist.txt`
    + `filelist.txt`的内容都是下载链接
