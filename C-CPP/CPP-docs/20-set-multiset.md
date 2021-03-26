# 1. set 基本概念
+ set 所有元素都会在插入时自动排序
+ 本质：set/multiset 属于关联式容器，底层结构时用二叉树实现
+ set 和 multiset 的区别
  + set 不允许容器中有重复的元素
  + multiset 允许容器内有重复元素

# 2. set 构造函数和赋值
+ `set<T> st;` 默认构造函数
+ `set(const set &st);` 拷贝构造函数
+ `set& operator=(const set &st);` 重载等号操作符

```cpp
#include <iostream>
#include <set>

using namespace std;

void printSet(const set<int> &st) {
    for(set<int>::iterator it=st.begin(); it != st.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    set<int> st;
    st.insert(3);
    st.insert(2);
    st.insert(1);
    st.insert(1);
    st.insert(4);
    printSet(st);

    set<int> st2;
    st2 = st;
    printSet(st2);

    set<int> st3(st);
    printSet(st3);

}


int main() {
    test01();
    return 0;
}
```

# 3. set 大小和交换
+ 函数原型
+ `empty();` 判断容器是否为空
+ `size();` 返回容器中元素的个数
+ `swap(st);` 交换两个集合容器

```cpp
#include <iostream>
#include <set>

using namespace std;

void printSet(const set<int> &st) {
    for(set<int>::iterator it=st.begin(); it != st.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    set<int> st;
    st.insert(3);
    st.insert(2);
    st.insert(1);
    st.insert(1);
    st.insert(4);
    printSet(st);

    cout << "st.size() = " << st.size() << endl;
    cout << "st.empty() = " << st.empty() << endl;

    set<int> st2;
    st2.insert(199);
    st2.insert(299);
    st.swap(st2);

    printSet(st);
    printSet(st2);

}

int main() {
    test01();
    return 0;
}
```

# 4. set 插入和删除
+ `insert(elem);` 在容器中插入元素
+ `clear();` 清除所有元素
+ `erase(pos);` 删除 pos 迭代器所指的元素，返回下一个元素的迭代器
+ `erase(begin, end);` 删除区间 `[begin, end]` 的所有元素，返回下一个元素的迭代器
+ `erase(elem);` 删除容器中值为 elem 的元素

```cpp
#include <iostream>
#include <set>

using namespace std;

void printSet(const set<int> &st) {
    for(set<int>::iterator it=st.begin(); it != st.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    set<int> st;
    st.insert(3);
    st.insert(2);
    st.insert(1);
    st.insert(1);
    st.insert(4);
    printSet(st);

    // 删除
    st.erase(st.begin());
    printSet(st);

    // 删除集合中值为 3 的元素
    st.erase(3);
    printSet(st);

    // 清空
    st.erase(st.begin(), st.end());
    printSet(st);

    // 清空
    st.clear();
    printSet(st);
}

int main() {
    test01();
    return 0;
}
```

# 5. set 查找和统计
+ 函数原型
+ `find(key);` 查找 key 是否存在，若存在，返回该键的元素的迭代器，若不存在，返回 set.end()
+ `count(key);` 统计 key 元素的个数

```cpp
#include <iostream>
#include <set>

using namespace std;

void printSet(const set<int> &st) {
    for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    set<int> st;
    st.insert(3);
    st.insert(2);
    st.insert(1);
    st.insert(1);
    st.insert(4);
    printSet(st);

    // 查找
    set<int>::iterator pos = st.find(3);
    if (pos != st.end()) {
        cout << "查找到该元素 = " << *pos << endl;

    } else {
        cout << "没有查找到该元素" << endl;
    }

    // 统计
    int c = st.count(1);
    cout << c << endl;
    c = st.count(1111);
    cout << c << endl;

}

int main() {
    test01();
    return 0;
}
```

# 6. set 和 multiset 的区别
+ set 不可以插入重复数据，multiset 可以有重复数据
+ set 插入数据的同时会返回插入结构，表示插入是否成功
+ multiset 不会检测数据，因此可以重复插入

```cpp
#include <iostream>
#include <set>

using namespace std;

void printSet(const set<int> &st) {
    for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void printMultiset(const multiset<int> &st) {
    for (multiset<int>::iterator it = st.begin(); it != st.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    set<int> st;
    pair<set<int>::iterator, bool> ret;
    ret = st.insert(3);
    if (ret.second) {
        cout << "第一次插入成功" << endl;
    } else {
        cout << "第一次插入失败" << endl;
    }
    ret = st.insert(3);
    if (ret.second) {
        cout << "第二次插入成功" << endl;
    } else {
        cout << "第二次插入失败" << endl;
    }
    st.insert(2);
    st.insert(1);
    st.insert(1);
    st.insert(4);
    printSet(st);

    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    printMultiset(ms);

}

int main() {
    test01();
    return 0;
}
```

# 7. pair 对组创建
+ 成对出现的数据，利用队组可以返回两个数据
+ 两种创建方式
+ `pair<type, type> p (value1, value2);`
+ `pair<type, type> p = make_pair(value1, value2);`

```cpp
#include <iostream>

using namespace std;

void test01() {
    pair<int, bool> s1(18, true);
    cout << s1.first << "  " << s1.second << endl;

    pair<int ,bool> s2 = make_pair(19, false);
    cout << s2.first << "  " << s2.second << endl;

}

int main() {
    test01();
    return 0;
}
```

# 8. set 容器排序
+ set 容器默认排序规则为从小到大
+ 利用仿函数，重载 `()` 运算符，通过返回值可以改变排序规则
+ 在插入数据之前就要确定排序规则

```cpp
#include <iostream>
#include <set>

using namespace std;

void printSet(const set<int> &s) {
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

// 仿函数
class MyCompare {
public:
    bool operator()(int v1, int v2) {
        // 降序 v1 > v2;
        // 升序 v1 < v2;
        return v1 > v2;
    }
};

void printSetMyCompare(const set<int, MyCompare> &s) {
    for (set<int, MyCompare>::const_iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    set<int> s1;
    s1.insert(1);
    s1.insert(3);
    s1.insert(2);
    s1.insert(9);
    s1.insert(6);
    s1.insert(4);

    printSet(s1);

    set<int, MyCompare> s2;
    s2.insert(1);
    s2.insert(3);
    s2.insert(2);
    s2.insert(9);
    s2.insert(6);
    s2.insert(4);

    printSetMyCompare(s2);

}

int main() {
    test01();
    return 0;
}
```

# 8. set 容器排序-自定义数据类型
+ 自定义数据类型，都会指定排序规则，但是指定排序规则的字段不能重复，如果重复，那么后边的就会被忽略掉

```cpp
#include <iostream>
#include <string>
#include <set>

using namespace std;

class Person {
public:
    string m_Name;
    int m_Age;
public:
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }
};

class PersonCompare {
public:
    bool operator()(const Person &p1, const Person &p2) {
        return p1.m_Age > p2.m_Age;
    }
};

void test01() {
    // 自定义数据类型，都会指定排序规则，但是指定排序规则的字段不能重复，如果重复，那么后边的就会被忽略掉
    set<Person, PersonCompare> s;
    Person p1("Sherry", 18);
    Person p2("Jack", 19);
    Person p3("Tom", 20);
    Person p4("Marry", 32);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    for (set<Person, PersonCompare>::iterator it = s.begin(); it != s.end(); it++) {
        cout << it->m_Name << "  " << it->m_Age << endl;
    }

}

int main() {
    test01();
    return 0;
}
```
