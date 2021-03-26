# 1. SQL 和 NoSQL
## 1.1 SQL
+ 特点
    + 数据结构化存储在二维表中
    + 支持事务的 ACID
    + 支持使用 SQL 语言对存储在其中的数据进行操作 
+ 适用场景
    + 数据库存在着一定的关系，需要关联查询数据的场景
    + 支持事务支持的业务场景
    + 需要使用 SQL 语言灵活操作数据的场景

## 1.2 NoSQL
+ 特点
    + 存储结构灵活，没有固定的结构
    + 比 SQL 占用更多的存储空间
    + 对事务的支持比较弱，但是对数据的并发处理性能高
    + 大多不支持 SQL 语言操作数据
+ 适用场景
    + 数据结构不固定的场景
    + 对事务要求不高，但读写并发比较大的场景
    + 对数据的处理操作比较简单的场景

# 2. 选择什么样的关系型数据库
## 2.1 选择数据库的原则
+ 数据库的使用广泛性
+ 数据库的可扩展性
+ 数据库的安全性和稳定性
+ 数据库所支持的操作系统
+ 数据库的使用成本（软件成本，软件维护成本，软件人员成本）

## 2.2 MySQL 数据库

+ 可扩展性
    + 支持基于二进制日志的逻辑复制
    + 存在多种第三方数据库中间层，支持读写分离及分库分表
+ 安全性和稳定性
    + 主从复制集群可达到 99% 的可用性
    + 配合主从复制高可用架构可以达到 99.99% 的可用性
    + 支持对存储在 MySQL 的数据进行分级安全控制
+ 支持的系统
    + 支持 linux
    + 支持 windows
+ 使用成本
    + 社区版本免费
    + 使用人员众多，可以方便的获取技术支持

# 3. MySQL 数据库设计

## 3.1 逻辑设计

+ 宽表模式存在的问题
    + 数据更新异常：修改一行中某列的值时，同时修改了多行数据
    + 数据插入异常：部分数据由于缺失主键信息而无法写入表中
    + 数据删除异常：删除某一数据时不得不删除另一数据
    + 数据冗余：相同的数据在一个表中出现了很多次

+ 宽表模式适用场景
    + 配合列存储的数据报表应用

## 3.2 数据库设计范式
+ 第一范式：表中的所有字段都是不可再分的
+ 第二范式：表中必须存在业务主键，并且非业务主键依赖于全部业务主键
+ 第三范式：表中的非主键列之间不能互相依赖

## 3.3 存储引擎
+ MyISAM，不支持事务，MySQL 5.6 之前的默认引擎，最常用的非事务性存储引擎，读写会对数据加锁，影响数据性能
+ CSV，不支持事务，以 CSV 格式存储的非事务性存储引擎
+ Archive，不支持事务，只允许查询和新增数据，而不允许修改的非事务性存储引擎
+ Memory，不支持事务，是一种容易丢失的非事务性存储引擎，性能高，在 MySQL 内部临时存储数据，加快 SQL 执行速度
+ InnoDB，支持事务，MySQL 5.6 之后的默认引擎，最常用的事务性存储引擎

## 3.4 InnoDB 存储引擎
+ 完全支持 ACID，不要在一个事务中同时使用事务性存储引擎和非事务性存储引擎
+ 数据按照主键聚集存储，使用自增 ID 作为数据主键
+ 支持行级别锁及多版本并发控制(Multiversion concurrency control， MCC 或 MVCC)
+ 支持 B tree 和自适应 Hash 索引
+ 支持全文和空间索引

## 3.5 MySQL 支持的数据类型

**整数类型**

|类型|存储空间|取值范围|
|---|---|---|
|tinyint|1字节|`SIGNED -128~127，UNSIGNED 0~255`|
|smallint|2字节|`SIGNED -3 2768~3 2767，UNSIGNED 0~6 5535`|
|mediumint|3字节|`SIGNED -838 8608~838 8607` **约838万** ，`UNSIGNED 0~1677 7215` **约1677万**|
|int|4字节|`SIGNED -21 4748 3648~21 4748 3647` **约21亿**，`UNSIGNED 0~42 9496 7295` **约42亿**|
|bigint|8字节|`SIGNED -92 2337 2036 8547 5808~92 2337 2036 8547 5807`，`UNSIGNED 0~1844 6744 0737 0955 1615`|

**浮点数类型**

浮点类型为 float 和 double，定点类型为 decimal。浮点类型和定点类型都可以使用 `(M, D)` 来表示，M 代表精度，总共的位数，D 代表标度，表示小数的位数。

decimal 类型实际上是以字符串形式存放的，最大取值范围与 double 相同，但是有效的取值范围由 M 和 D 决定。如果改变 M 而固定 D，那么取值范围将随 M 的变大而变大。

|类型|存储空间|是否精确类型|
|---|---|---|
|float|4字节|否|
|double|8字节|否|
|decimal|每4个字节存9个数字，小数点占一个字节|是|

**日期与时间类型**

|类型名称|日期格式|日期范围|存储需求|
|---|---|---|---|
|YEAR|YYYY|1901 ~ 2155|1 个字节|
|TIME|HH:MM:SS|-838:59:59 ~ 838:59:59|3 个字节|
|DATE|YYYY-MM-DD|1000-01-01 ~ 9999-12-3|3 个字节|
|DATETIME|YYYY-MM-DD HH:MM:SS|1000-01-01 00:00:00 ~ 9999-12-31 23:59:59|8 个字节|
|TIMESTAMP|YYYY-MM-DD HH:MM:SS|1980-01-01 00:00:01 UTC ~ 2040-01-19 03:14:07 UTC|4 个字节|

**字符串类型**

| 类型名称|说明|存储需求|
|---|---|---|
| CHAR(M)|固定长度非二进制字符串|M 字节，1<=M<=255|
| TINYTEXT|非常小的非二进制字符串|L+1字节，在此，L<255|
| VARCHAR(M)|变长非二进制字符串|L+1字节，在此，L< = M和 1<=M<=65535|
| TEXT|小的非二进制字符串|L+2字节，在此，L<65535|
| MEDIUMTEXT|中等大小的非二进制字符串|L+3字节，在此，L<16777215|
| LONGTEXT|大的非二进制字符串|L+4字节，在此，L<2^42 9496 7295|
| ENUM|枚举类型，只能有一个枚举字符串值|1或2个字节，取决于枚举值的数目 (最大值为65535)|
| SET|一个设置，字符串对象可以有零个或 多个SET成员|1、2、3、4或8个字节，取决于集合 成员的数量（最多64个成员）|

**选择合适的数据类型**
+ 优先选择符合存储数据需求的最小数据类型。
+ 谨慎使用 ENUM，TEXT 字符串类型。
+ 同财务相关的数值型数据，必需使用 decimal 类型

**为表和列选择合适的名字**
+ 所有数据库对象名称必需使用小写字母，可选用下划线分割
+ 所有数据库对象名称定义禁止使用 MySQL 保留关键字
+ 数据库对象的命名要能做到见名识意，并且最好不要超过 32 个字

**数据表命名规则**
+ 临时表必需以 tmp 为前缀，并以日期为后缀
+ 用于备份的库，表必需以 bak 为前缀，并以日期为后缀
+ 所有存储相同数据的列名和列类型都必须保持一致

## 3.6 数据库基本操作

**名字介绍**

+ `DB_NAME` 表示数据库名字
+ `TABLE_NAME` 表示数据表名字
+ `CHARSET_NAME` 表示字符集名字
+ `FIELD_NAME` 表示字段名字
+ `DATE_TYPE` 表示数据类型

---

**数据库操作**

+ 创建数据库账号 `CREATE USER IF NOT EXISTS <USERNAME>@'192.168.%.%' IDENTIFIED WITH 'mysql_native_password' by '<password>';`
+ 登录数据库 `mysql -u <username> -p;`
+ 对用户授权 `GRANT;`
+ 收回用户授权 `REVOKE;`
+ 创建数据库 `CREATE DATABASE IF NOT EXISTS <DB_NAME> DEFAULT CHARACTER SET utf8;`
+ 查看创建数据库时的定义声明 `SHOW CREATE DATABASE <DB_NAME>;`
+ 查看数据库列表 `SHOW DABABASES;`
+ 删除数据库 `DROP DATABASE IF EXISTS <DB_NAME>`
+ 使用数据库 `USE <DB_NAME>;`
CREATE USER IF NOT EXISTS weizhiqimail@'192.168.%.%' IDENTIFIED WITH 'mysql_native_password' by 'weizhiqimail';
---

GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '123456' WITH GRANT OPTION;
 FLUSH PRIVILEGES;

**数据表操作**

+ 创建数据表 

```mysql
CREATE TABLE IF NOT EXISTS <TABLE_NAME>(
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(30),
    age SMALLINT
);
```
+ 查看数据库的里所有数据表 `SHOW TABLES;`
+ 删除数据表 `DROP TABLE IF EXISTS <TABLE_NAME1>, <TABLE_NAME2>;`
+ 查看表结构 `DESCRIBE <TABLE_NAME>;` 或者 `DESC <TABLE_NAME>;`
+ 查看创建数据表时的定义声明 `SHOW CREATE TABLE <TABLE_NAME>;`

---

**修改数据表**

+ 修改数据表的名字 `ALTER TABLE <OLD_TABLE_NAME> RENAME TO <NEW_TABLE_NAME>;`
+ 修改数据表的字符集 `ALTER TABLE <TABLE_NAME> DEFAULT CHARACTER SET <CHARSET_NAME>`
+ 修改数据表的字段 `ALTER TABLE <TABLE_NAME> CHANGE <OLD_FIELD_NAME> <NEW_FIELD_NAME> <NEW_DATA_TYPE>;`
+ 修改数据表的字段类型 `ALTER TABLE <TABLE_NAME> MODIFY <FIELD_NAME> <DATA_TYPE>;`
+ 删除数据表中的某个字段 `ALTER TABLE <TABLE_NAME> DROP <FIELD_NAME>;`
+ 给数据表添加字段 `ALTER TABLE <TABLE_NAME> ADD <NEW_FIELD_NAME> <DATA_TYPE>;`
+ 在数据表开头添加字段 `ALTER TABLE <TABLE_NAME> ADD <NEW_FIELD_NAME> <DATA_TYPE> FIRST;` 
+ 在数据表中间位置添加字段 `ALTER TABLE <TABLE_NAME> ADD <NEW_FIELD_NAME> <DATA_TYPE> AFRER <EXIST_FIELD_NAME>;`

**数据库约束**
+ 主键约束
+ 外键约束
+ 唯一约束：唯一约束与主键约束有一个相似的地方，就是它们都能够确保列的唯一性。与主键约束不同的是，唯一约束在一个表中可以有多个，并且设置唯一约束的列是允许有空值的，虽然只能有一个空值。
+ 检查约束：检查约束是用来检查数据表中，字段值是否有效的一个手段。
+ 非空约束：非空约束用来约束表中的字段不能为空。
+ 默认值约束：默认值约束用来约束当数据表中某个字段不输入值时，自动为其添加一个已经设置好的值。

**数据表的操作**
+ 起别名 `SELECT <OLD_RESULT> AS <NEW_RESULT>` 或者 `SELECT <FIELD_NAME> <NEW_FIELD_NAME> FROM <TABLE_NAME>;`
