# 1. STL 的诞生
+ C++ 的面向对象和泛型编程思想，目的就是复用性的提升
+ 大多情况下，数据结构和算法都没有一套标准，导致被迫从事大量重复工作
+ 为了建议数据结构和算法的一套标准，诞生了 STL

# 2. STL 的基本概念
+ STL(Standard Template Library) 标准模板库
+ STL 从广义上分为：容器(container)、算法(algorithm)和迭代器(iterator)
+ **容器** 和 **算法** 之间通过 **迭代器** 进行无缝连接
+ STL 几乎所有的代码都采用了模板类或者模板函数

# 3. STL 六大组件
+ STL 大体分为六大组件，分别是：容器、算法、迭代器、仿函数、适配器(配接器)和空间配置器
+ 容器：各种数据结构，如 vector、list、deque、set 和 map 等用来存放数据
+ 算法: 各种常见的算法，如 sort、find、copy 和 for_each 等
+ 迭代器：扮演了容器与算法之间的胶合剂
+ 仿函数：行为类似含糊，可以作为算法的某种策略
+ 适配器：一种用来装饰容器或者仿函数或者迭代器接口的东西
+ 空间配置器：负责空间的配置与管理

# 4. STL 中容器、算法和迭代器
## 4.1 容器
+ STL 容器就是将运用最广泛的一些数据结构实现出来
+ 常用的数据结构：数组、链表、树、队列、集合、映射表等
+ 这些容器分为序列式容器和关联式容器两种
  + 序列式容器：强调值的排序，序列式容器中的每个元素均有固定的位置
  + 关联式容器：二叉树结构，各元素之间没有严格的物理上的顺序关系

## 4.2 算法
+ 有限的步骤，解决逻辑或数学上的问题，这门学科叫做算法
+ 算法要通过迭代器才能访问到容器中的元素
+ 算法分为：**质变算法** 和 **非质变算法**
  + 质变算法：是指运算过程中会更改区间内的元素的内容，比如拷贝、替换、删除等
  + 非质变算法：是指运算过程中不会更改区间内的元素，比如查找、计数、遍历、寻找极值等

## 4.3 迭代器
+ 容器和算法之间的粘合剂
+ 提供一种方法，使之能够依序寻访某个容器所含的某个元素，而又无需暴露该容器的内部表示方式。
+ 每个容器都有自己专属的迭代器
+ 迭代器使用非常类似指针
+ 迭代器的种类

|种类|功能|支持运算|
|---|----|-------|
|输入迭代器|对数据的只读访问|只读，支持 `++`、`==`、`!=`|
|输出迭代器|对数据的只写访问|只写，支持 `++`|
|前进迭代器|读写操作，并能向前推进迭代器|读写，支持 `++`、`==`、`!=`|
|双向迭代器|读写操作，并能向前和向后操作|读写，支持 `++`、`--`|
|随机访问迭代器|读写操作，可以以跳跃的方式访问任意数据，功能最强的迭代器|读写，支持 `++`、`--`、`[n]`、`-n`、`<`、`<=`、`>`、`>=`

+ 常用的容器中迭代器的种类为双向迭代器和随机访问迭代器

# 5. 容器算法迭代器初识
+ STL 中最常用的容器为 Vector，可以理解为数组

## 5.1 vector 存放内置数据类型
+ 容器: `vector`
+ 算法: `for_each`
+ 容器: `vector<int>::iterator`

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// vector 容器存放内置数据类型
using namespace std;

// while 循环遍历
void test01() {
    // 创建一个 vector 容器，数组
    vector<int> v;

    // 向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    // 通过迭代器访问容器中的数据
    // v.begin(); 是一个起始迭代器，指向容器中第一个元素
    vector<int>::iterator itBegin = v.begin();

    // v.end(); 是一个结束迭代器，指向容器中最后一个元素的下一个位置
    vector<int>::iterator itEnd = v.end();

    while (itBegin != itEnd) {
        cout << "*itBegin: " << *itBegin << endl;
        itBegin++;
    }
}

// for 循环遍历
void test02() {
    // 创建一个 vector 容器，数组
    vector<int> v;

    // 向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "*it: " << *it << endl;
    }
}

void myPrint (int val) {
    cout << val << endl;
}

// 内置算法 for_each
void test03 () {
    // 创建一个 vector 容器，数组
    vector<int> v;

    // 向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    // 利用回调的技术
    for_each(v.begin(), v.end(), myPrint);
}


int main() {
    test03();
    return 0;
}
```

## 5.2 vector 存放自定义数据类型
+ 存放自定义数据类型和存放自定义数据类型指针

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// vector 存放自定义数据类型
class Person {
public:
    string m_Name;
    int m_Age;

    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }
};

void myPrint(Person &p) {
    cout << "name = " << p.m_Name << " age = " << p.m_Age << endl;
}

void test01() {
    vector<Person> v;
    Person p1("A", 1);
    Person p2("B", 2);
    Person p3("C", 3);
    Person p4("D", 4);
    Person p5("E", 5);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    vector<Person>::iterator itBegin = v.begin();
    vector<Person>::iterator itEnd = v.end();

    cout << "while 循环" << endl;

    while (itBegin != itEnd) {
        cout << "name = " << itBegin->m_Name << " age = " << itBegin->m_Age << endl;
        itBegin++;
    }

    cout << "for 循环" << endl;

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "name = " << (*it).m_Name << " age = " << (*it).m_Age << endl;
    }

    cout << "for_each 循环" << endl;

    for_each(v.begin(), v.end(), myPrint);
}

void myPrintPointer(Person *p) {
    cout << "name = " << p->m_Name << " age = " << p->m_Age << endl;
}

// 自定义数据类型的指针
void test02() {
    vector<Person *> v;
    Person p1("A", 1);
    Person p2("B", 2);
    Person p3("C", 3);
    Person p4("D", 4);
    Person p5("E", 5);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    vector<Person *>::iterator itBegin = v.begin();
    vector<Person *>::iterator itEnd = v.end();

    cout << "while 循环" << endl;

    while (itBegin != itEnd) {
        cout << "name = " << (*itBegin)->m_Name << " age = " << (*itBegin)->m_Age << endl;
        itBegin++;
    }

    cout << "for 循环" << endl;

    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "name = " << (*it)->m_Name << " age = " << (*it)->m_Age << endl;
    }

    cout << "for_each 循环" << endl;

    for_each(v.begin(), v.end(), myPrintPointer);
}

int main() {
    test02();
    return 0;
}
```

## 5.3 vector 容器嵌套容器
+ 容器中嵌套容器，将所有数据进行遍历输出

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 容器嵌套容器
void test01() {
    vector<vector<int> > v;

    // 创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for (int i = 0; i < 4; i++) {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    // 把小容器都放到大容器里
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    // 通过大容器遍历操作
    for (vector<vector<int> >::iterator it = v.begin(); it != v.end(); it++) {
        // (*it) 就是一个容器，类型是 vector<int>
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
            cout << (*vit);
        }
        cout << endl;
    }
}

int main() {
    test01();
    return 0;
}
```