# 1. string 基本概念
+ 本质：string 是 C++ 风格的字符串，而 string 本质上是一个类
+ string 和 char* 区别
  + char * 是一个指针
  + string 是一个类，类内部封装了 char*，管理这个字符串，是 char* 型的容器
+ 特点：
  + string 内部封装了很多成员方法，copy，find，delete，replace，insert
  + string 管理 char* 所分配的内存，不用担心复制越界等，由类内部进行负责

# 2. string 构造函数
+ `string();` 创建一个空的字符串，例如 `string str;`
+ `string(const char* s);` 使用字符串 s 初始化
+ `string(const string& str);` 拷贝构造函数，使用一个 string 对象初始化另一个 string 对象
+ `string(int n, char c);` 使用 n 个字符 c 初始化

```cpp
#include <iostream>
#include <string>

using namespace std;

void test01() {
    string s1;
    cout << "s1 = " << s1 << "----" << endl;
    const char *s2 = "mark";
    cout << "s2 = " << s2 << endl;

    string s3(s2);
    cout << "s3 = " << s3 << endl;

    string s4(5, 'a');
    cout << "s4 = " << s4 << endl;
}

int main() {
    test01();
    return 0;
}
```

# 3. string 赋值操作
+ 功能：给 string 字符串进行赋值
+ 赋值的函数原型
+ `string& operator=(const char* s);` char* 类型字符串，赋值给当前的字符串
+ `string& operator=(const string &s);` 把字符串 s 赋值给当前的字符串
+ `string& operator=(char c);` 字符赋值给当前的字符串
+ `string& assign=(const char *s);` 把字符串 s 赋值给当前的字符串
+ `string& assign=(const char *s, int n);` 把字符串 s 的前 n 个字符赋值给当前的字符串
+ `string& assign=(const string &s);` 把字符串 s 赋值给当前字符串
+ `string& assign=(int n, char c);` 用 n 个字符 c 赋值给当前字符串

```cpp
#include <iostream>
#include <string>

using namespace std;

void test01() {
    string str1;
    str1 = "hello, world";
    cout << str1 << endl;

    string str2;
    str2 = str1;
    cout << str2 << endl;

    str1 = 'a';
    cout << str1 << endl;

    string str4;
    str4.assign("hello, cpp");
    cout << str4 << endl;

    string str5;
    str5.assign("hello, cpp", 5);
    cout << str5 << endl;

    string str6;
    str6.assign(str5);
    cout << str6 << endl;

    string str7;
    str7.assign(5, 'a');
    cout << str7 << endl;
}

int main() {
    test01();
    return 0;
}
```

# 4. string 字符串拼接
+ 功能：实现在字符串末尾拼接字符串
+ 函数原型
+ `string& operator+=(const char* str);` 重载+=操作符
+ `string& operator+=(const char c);` 重载+=操作符
+ `string& operator+=(const string& str);` 重载+=操作符
+ `string& append(const char* s);` 把字符串 s 连接到当前字符串结尾
+ `string& append(const char* s, int n);` 把字符串 s 的前 n 个字符连接到当前字符串结尾
+ `string& append(const string &s);` 同 operator+=(const string& str);
+ `string& append(const string &s, int pos, int n)` 字符串 s 中从 pos 开始的 n 个字符连接到字符串结尾

# 5. string 查找和替换
+ 函数原型
+ `int find(const string& str, int pos = 0) const;` 查找 str 第一次出现的位置，从 pos 开始查找
+ `int find(const char* s, int pos = 0) const;` 查找 s 第一次出现的位置，从 pos 开始查找
+ `int find(const char* s, int pos, int n) const;` 从 pos 开始查找 s 的前 n 个字符第一次出现的位置
+ `int find(const char c, int pos = 0) const;` 查找字符 c 第一次出现的位置
+ `int rfind(const string& str, int pos = npos) const;` 查找 str 最后一次的位置，从 pos 开始查找
+ `int rfind(const char* s, int pos = npos) const;` 查找 s 最后一次的位置，从 pos 开始查找
+ `int rfind(const char* s, int pos, int n) const;` 从 pos 开始查找 s 的前 n 个字符最后一次位置
+ `int rfind(const char c, int pos = 0) const;` 查找字符 c 最后一次出现的位置
+ `string& replace(int pos, int n, const string& str);` 替换从 pos 开始 n 个字符为字符串 str
+ `string& replace(int pos, int n, const char* s);` 替换从 pos 开始的 n 个字符为字符串 s
+ find 查找是从左往右，rfind 查找是从右往左
+ find 找到字符串后返回查找的第一个字符串位置，找不到返回 -1
+ replace 在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串

# 6. string 字符串比较
+ 字符串比较时按字符的 ASCII 码进行对比
  + 相等返回 0
  + 大于返回 1
  + 小于返回 -1
+ 函数原型
  + `int compare(const string &s) const;`
  + `int compare(const char *s) const;`

# 7. string 字符存取
+ `char& operator[](int n);` 通过 `[]` 方式取字符
+ `char& at(int n);` 通过 at 方法获取字符

# 8. string 插入和删除
+ 函数原型
+ `string& insert(int pos, const char *s);` 插入字符串
+ `string& insert(int pos, const string& str);` 插入字符串
+ `string& insert(int pos, int n, char c);` 在指定位置插入 n 个字符 c
+ `string& erase(int pos, int n = npos);` 删除从 pos 开始的 n 个字符

# 9. string 子串
+ 函数原型
+ `string substr(int pos = 0, int n = npos) const;` 返回由 pos 开始的 n 个字符组成的字符串
