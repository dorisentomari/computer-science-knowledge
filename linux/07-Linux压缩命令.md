#Linux压缩命令
[TOC]
**常用的压缩格式:**
+ *.zip
+ *.gz
+ *.bz
+ *.tar.gz
+ *.tar.bz2

### zip格式
+ 压缩文件
    + `zip 压缩后的文件名 文件名`
+ 压缩目录
    + `zip -r 压缩后的文件名 文件名`
+ 解压缩
    + `unzip 压缩后的文件`

### gz格式
+ 压缩文件
    + `gzip 源文件`压缩为.gz格式的压缩文件,源文件就会消失
    + `gzip -c 源文件 > 压缩文件`压缩为.gz格式,源文件保留
        + `gzip -c one > one.gz`
    + `gzip -r 目录`压缩目录下所有的子文件,但是不能压缩目录
+ 解压缩
    + `gzip -d 压缩包名`
    + `gunzip 压缩文件`

### bz2格式
+ 压缩
    + `bzip2 源文件`压缩为.bz2格式,不保留源文件
    + `bzip2 -k 源文件`压缩后保留源文件
    + 注意:bzip2命令不能压缩目录
+ 解压缩
    + `bzip2 -d 压缩文件` -k 保留压缩文件
    + `bunzip2 压缩文件` -k 保留压缩文件

### tar.gz格式
+ 压缩
    + `tar -cvf 打包文件名 源文件`
    + -c 打包
    + -v 显示过程
    + -f 指定打包后的文件名
    + `tar -cvf a.tar a`
+ 解压缩
    + `tar -xvf 打包文件名`
    + -x 解打包
    + `tar -xvf a.tar`
+ .tar.gz格式是先打包为.tar格式，再压缩为.gz格式
    + `tar -zcvf 压缩包名.tar.gz 源文件`
        + `-z`压缩为.tar.gz格式
    + `tar -zxvf 压缩包名.tar.gz`
        + `-x` 解压缩为.tar.gz格式
+ 指定压缩目录
    + `tar -zcvf /路径/压缩包名.tar.gz 源文件`
+ 只查看压缩内容，看不解压
    + `tar -ztvf 压缩包.tar.gz 源文件`

### tar.bz2格式
+ 压缩
    + `tar -jcvf 打包文件名 源文件`
    + -c 打包
    + -v 显示过程
    + -f 指定打包后的文件名
    + `tar -jcvf a.tar a`
+ 解压缩
    + `tar -jcvf 压缩包名.tar.bz2 源文件`
        + `-z`压缩为.tar.bz2格式
    + `tar -jxvf 压缩包名.tar.bz2`
        + `-x` 解压缩为.tar.bz2格式
+ 指定解压缩的位置
    + `tar -jxvf a.tar.bz2 -C /tmp/`


