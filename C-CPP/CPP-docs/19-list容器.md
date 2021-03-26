# 1. list 链表基本概念
+ 功能：将数据进行链式存储，由一系列结点组成
+ 链表：是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的。
+ 结点的组成：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域
+ STL 中的链表是一个双向循环链表，每一个结点记录了上一个结点的地址，也记录了下一个结点的位置，首结点的上一个结点指针为 NULL，尾结点的下一个结点指针为 NULL
+ 优点：
  + 采用动态存储分配，不会造成内存浪费和溢出
  + 链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素
+ 缺点：
  + 链表灵活，但是空间(指针域)和时间(遍历)额外消耗较大
+ list 有一个重要的特点，插入操作和删除操作都不会造成原有 list 迭代器的失效，这个在 vector 里是不成立的
+ 由于链表的存储方式并不是连续的内存空间，因此链表 list 中的迭代器只支持前移和后移，属于双向迭代器
+ 总结：STL中的链表 list 和 vector 是最常被使用的容器，各有优缺点，

# 2. list 构造函数
+ 函数原型
+ `list<T> lst;` list 采用类模板实现，对象的默认构造函数
+ `list(begin, end);` 构造函数将 `[begin, end]` 区间中的元素拷贝给本身
+ `list(n, elem);` 构造函数将 n 个 elem 拷贝给本身
+ `list(const list &lst);` 拷贝构造函数

```cpp
#include <iostream>
#include <list>

using namespace std;

void printList(const list<int> &lst) {
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    list<int> lst;

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);

    printList(lst);

    list<int>L2(lst.begin(), lst.end());
    printList(L2);

    list<int>L3(L2);
    printList(L3);

    list<int> L4(10, 100);
    printList(L4);

}

int main() {
    test01();
    return 0;
}
```

# 3. list 赋值和交换
+ 功能描述：给 list 容器进行赋值，以及交换 list 容器
+ 函数原型
+ `assign(begin, end);` 将 `[begin, end]` 区间中的数据拷贝赋值给本身
+ `assign(n, elem);` 将 n 个 elem 拷贝赋值给本身
+ `list& operator=(const list &lst);` 重载等号操作符
+ `swap(lst);` 将 lst 与本身的元素交换

```cpp
#include <iostream>
#include <list>

using namespace std;

void printList(const list<int> &lst) {
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    list<int> L1;

    L1.push_back(1);
    L1.push_back(2);
    L1.push_back(3);
    L1.push_back(4);
    printList(L1);

    list<int> L2;
    L2 = L1;
    printList(L2);

    list<int> L3;
    L3.assign(L2.begin(), L2.end());
    printList(L3);

    list<int> L4;
    L4.assign(10, 100);
    printList(L4);
}

void test02() {
    cout << "交换前" << endl;
    list<int> L1;
    L1.push_back(1);
    L1.push_back(2);
    L1.push_back(3);
    L1.push_back(4);
    printList(L1);

    list<int> L2;
    L2.push_back(1 * 1);
    L2.push_back(2 * 2);
    L2.push_back(3 * 3);
    L2.push_back(4 * 4);
    printList(L2);

    cout << "交换后" << endl;

    L1.swap(L2);
    printList(L1);
    printList(L2);

}


int main() {
    test02();
    return 0;
}
```

# 4. list 大小操作
+ 函数原型
+ `empty();` 判断容器是否为空
+ `size();` 返回容器中元素的个数
+ `resize(int num);` 重新指定容器的长度为 num，若容器变长，则以默认值 0 填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
+ `resize(int num, elem);` 重新指定容器的长度为 num，若容器变长，则以 elem 填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。

```cpp
#include <iostream>
#include <list>

using namespace std;

void printList(const list<int> &lst) {
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    list<int> L1;
    for (int i = 0; i < 20; ++i) {
        L1.push_back(i);
    }
    printList(L1);

    bool isEmpty = L1.empty();
    if (isEmpty) {
        cout << "L1 is empty" << endl;
    }
    cout << "L1 is not empty" << endl;

    int size = L1.size();
    cout << "size = " << size << endl;

    for (int i = 20; i < 40; ++i) {
        L1.push_back(i);
    }
    printList(L1);
    
    L1.resize(20);
    printList(L1);

    L1.resize(30, 0);
    printList(L1);
}

int main() {
    test01();
    return 0;
}
```

# 5. list 插入和删除
+ 函数原型
+ `push_back(elem);` 尾部插入元素 elem
+ `pop_back();` 删除最后一个元素
+ `push_front(elem);` 头部插入元素 elem
+ `pop_front();` 删除头部元素
+ `insert(const_iterator pos, elem);` 迭代器指向位置 pos 插入元素 elem
+ `insert(const_iterator pos, int count, elem);` 迭代器指向位置 pos 插入 count 个元素 elem
+ `erase(const_iterator pos);` 删除迭代器指向的元素
+ `erase(const_iterator pos, const_iterator start, const_iterator end);` 在 pos 位置插入 `[begin, end]` 区间的数据，无返回值
+ `clear();` 删除容器中所有元素
+ `erase(begin, end);` 删除 `[begin, end]` 区间里的数据，返回下一个数据位置
+ `erase(pos);` 删除 pos 位置的数据，返回下一个数据的位置
+ `remove(elem);` 删除容器中所有与 elem 值匹配的元素

```cpp
#include <iostream>
#include <list>

using namespace std;

void printList(const list<int> &lst) {
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    list<int> L1;
    L1.push_back(1);
    L1.push_back(2);
    L1.push_front(3);
    L1.push_front(4);
    printList(L1);

    L1.pop_front();
    printList(L1);

    L1.pop_back();
    printList(L1);

    list<int>::iterator it = L1.begin();
    it++;
    L1.insert(it, 200);
    L1.insert(it, 200);
    printList(L1);

    it = L1.begin();
    L1.erase(it);
    printList(L1);

    L1.remove(200);
    printList(L1);

    L1.clear();
    printList(L1);
}

int main() {
    test01();
    return 0;
}
```

# 6. list 数据存取
+ 函数原型
+ `front();` 返回容器中的第一个数据元素
+ `back();` 返回容器中的最后一个数据元素
+ 由于链表不是采用连续线性空间存储数据，所以迭代器不支持随机访问，所以不能采用 `[]` 或者 at 方式访问数据

```cpp
#include <iostream>
#include <list>

using namespace std;

void printList(const list<int> &lst) {
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    list<int> L1;

    L1.push_back(1);
    L1.push_back(2);
    L1.push_back(3);
    L1.push_back(4);

    cout << L1.front() << endl;
    cout << L1.back() << endl;


    list<int>::iterator it = L1.begin();
    it++;
    // t = t + 1;
    cout << *it << endl;
}

int main() {
    test01();
    return 0;
}
```

# 7. list 反转和排序
+ 函数原型
+ `reverse();` 反转链表
+ `sort();` 链表排序

```cpp
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void printList(const list<int> &lst) {
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    list<int> L1;

    L1.push_back(1);
    L1.push_back(6);
    L1.push_back(2);
    L1.push_back(4);

    L1.reverse();
    printList(L1);

    L1.sort();
    printList(L1);
}

bool myCompare (int v1, int v2) {
    // 降序，第一个数大于第二个数
    return v1 >  v2;
}

void test02() {
    list<int> L1;

    L1.push_back(1);
    L1.push_back(6);
    L1.push_back(2);
    L1.push_back(4);

    cout << "排序前" << endl;
    printList(L1);

    cout << "排序后" << endl;
    // 报错，原因是所有不支持随机访问迭代器容器，都不能使用标准算法
    // sort(L1.begin(), L1.end());
    // 不支持随机访问迭代器的容器，内部会提供会提供一些算法
    L1.sort(myCompare);
    printList(L1);

}

int main() {
    test02();
    return 0;
}
```

# 8. list 排序案例
+ 描述：将 Person 自定义数据类型进行排序，Person 中属性由姓名、年龄、身高
+ 排序规则：按照年龄进行排序，如果年龄相同按照身高排序

```cpp
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void printList(const list<int> &lst) {
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

class Person {
public:
    string m_Name;
    int m_Age;
    int m_Height;

    Person(string name, int age, int height) {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }
};

bool comparePerson(Person &p1, Person &p2) {
    if (p1.m_Age != p2.m_Age) {
        return p1.m_Age < p2.m_Age;
    }
    return p1.m_Height < p2.m_Height;
}

void test01() {
    list<Person> L1;
    Person p1("Tom", 19, 174);
    Person p2("Mike", 18, 172);
    Person p3("Jack", 17, 170);
    Person p4("Sherry", 17, 165);

    L1.push_back(p1);
    L1.push_back(p2);
    L1.push_back(p3);
    L1.push_back(p4);

    for (list<Person>::iterator it = L1.begin(); it != L1.end(); it++) {
        cout << "姓名 = " << (*it).m_Name << "  年龄 = " << (*it).m_Age << "  身高 = " << (*it).m_Height << endl;
    }

    cout << "------------------------------" << endl;

    L1.sort(comparePerson);
    for (list<Person>::iterator it = L1.begin(); it != L1.end(); it++) {
        cout << "姓名 = " << (*it).m_Name << "  年龄 = " << (*it).m_Age << "  身高 = " << (*it).m_Height << endl;
    }
}


int main() {
    test01();
    return 0;
}
```
