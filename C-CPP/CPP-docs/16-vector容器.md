# 1. vector 基本概念
+ vector 数据结构和数组非常相似，也称为单端数组
+ vector 与普通数组的区别
  + 数组是静态空间，而 vector 可以动态扩展
+ 动态扩展不是在原有空间之后续接新空间，而是找更大的内存空间，跟后将原数据拷贝新空间，释放原空间
+ vector 容器的迭代器是支持随机访问的迭代器

# 2. vector 的构造函数
+ 功能描述：创建 vector 容器
+ 函数原型
+ `vector<T> v;` 采用模板实现类实现，默认构造函数
+ `vector(v.begin(), v.end());` 将 `v[begin(), end()]` 区间中的元素拷贝给本身
+ `vector(n elem);` 构造函数将 n 个 elem 拷贝给本身
+ `vector(const vector &vec);` 拷贝构造函数

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVector(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << "  ";
    }
    cout << endl;
}

// vector 容器
void test01() {
    // 默认构造
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }

    printVector(v1);

    // 通过区间方式进行构造
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    // n 个 elem 方式构造
    vector<int> v3(10, 100);
    printVector(v3);

    // 拷贝构造函数
    vector<int> v4(v3);
    printVector(v4);
}

int main() {
    test01();
    return 0;
}
```

# 3. vector 赋值操作
+ 函数原型
+ `vector& operator=(const vector &vec);` 重载等号操作符
+ `assign(bed, end);` 将 `[bed, end]` 区间中的数据拷贝赋值给本身
+ `assign(n, elem);` 将 n 个 elem 拷贝赋值给本身

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVector(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << "  ";
    }
    cout << endl;
}

// vector 容器
void test01() {

    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    // 重载 = 运算符
    vector<int> v2;
    v2 = v1;
    printVector(v2);

    // assign
    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);

    // n 个 elem 方式赋值
    vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);

}

int main() {
    test01();
    return 0;
}
```

# 4. vector 容量和大小
+ 函数原型
+ `empty();` 判断容器是否为空
+ `capacity();` 容器的容量
+ `size();` 返回容器中元素的个数
+ `resize(int num);` 重新指定容器的长度为 num，若容器变长，则以默认值 0 填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
+ `resize(int num, elem);` 重新指定容器的长度为 num，若容器变长，则以 elem 填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVector(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << "  ";
    }
    cout << endl;
}

// vector 容器
void test01() {
    vector<int> v1;
    for (int i = 0; i < 20; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    bool isEmpty = v1.empty();
    if (isEmpty) {
        cout << "v1 is empty" << endl;
    }
    cout << "v1 is not empty" << endl;

    int size = v1.size();
    cout << "size = " << size << endl;

    int capacity = v1.capacity();
    cout << "capacity = " << capacity << endl;

    for (int i = 20; i < 40; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    capacity = v1.capacity();
    cout << "capacity = " << capacity << endl;

    v1.resize(20);
    printVector(v1);

    v1.resize(30, 0);
    printVector(v1);
}

int main() {
    test01();
    return 0;
}
```

# 5. vector 插入和删除
+ 函数原型
+ `push_back(elem);` 尾部插入元素 elem
+ `pop_back();` 删除最后一个元素
+ `insert(const_iterator pos, elem);` 迭代器指向位置 pos 插入元素 elem
+ `insert(const_iterator pos, int count, elem);` 迭代器指向位置 pos 插入 count 个元素 elem
+ `erase(const_iterator pos);` 删除迭代器指向的元素
+ `erase(const_iterator start, const_iterator end);` 删除迭代器从 start 到 end 之间的元素
+ `clear();` 删除容器中所有元素

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVector(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << "  ";
    }
    cout << endl;
}

// vector 容器
void test01() {
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    v1.insert(v1.begin(), 2,30);
    printVector(v1);

    v1.erase(v1.begin());
    printVector(v1);

    v1.erase(v1.begin(), v1.end());
    printVector(v1);

    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    v1.clear();
    printVector(v1);
}

int main() {
    test01();
    return 0;
}
```

# 6. vector 数据存取
+ 函数原型
+ `at(int idx);` 返回索引 idx 所指的数据
+ `operator[];` 返回索引 idx 所指的数据
+ `front();` 返回容器中的第一个数据元素
+ `back();` 返回容器中的最后一个数据元素

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// vector 容器数据存取
void printVector(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << "  ";
    }
    cout << endl;
}

// vector 容器
void test01() {
   vector<int> v1;
   for(int i = 0; i < 10; i++) {
       v1.push_back(i);
   }

    for (int i = 0; i < v1.size(); ++i) {
        cout << "v1.at(" << i << ") = " << v1.at(i) << endl;
        cout << "v1[" << i << "] = " << v1.at(i) << endl;
    }

    cout << "v1.front() = " << v1.front() << endl;
    cout << "v1.back() = " << v1.back() << endl;

}

int main() {
    test01();
    return 0;
}
```

# 7. vector 互换容器
+ 函数原型
+ `v1.swap(v2);` 将 v1 和 v2 的元素互换
+ 用途：
  + 可以用 swap 可以收缩内存空间，实际上是创建一个匿名对象，匿名对象和 v 交换，交换后两个容器的大小都变化了，之后匿名容器就被系统回收掉了

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// vector 容器数据存取
void printVector(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << "  ";
    }
    cout << endl;
}

// vector 容器
void test01() {
    vector<int> v1;

    cout << "交换前的数据" << endl;

    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }

    printVector(v1);

    vector<int> v2;
    for (int j = 10; j >= 0; j--) {
        v2.push_back(j);
    }

    printVector(v2);

    cout << "交换后的数据" << endl;

    v1.swap(v2);
    printVector(v1);
    printVector(v2);

}

void test02() {
    vector<int> v1;

    for (int i = 0; i < 100000; ++i) {
        v1.push_back(i);
    }

    cout << "v1 的容量: " << v1.capacity() << endl;
    cout << "v1 的大小: " << v1.size() << endl;

    v1.resize(10);
    cout << "v1.resize(10);" << endl;
    cout << "v1 的容量: " << v1.capacity() << endl;
    cout << "v1 的大小: " << v1.size() << endl;

    vector<int>(v1).swap(v1);
    cout << "vector<int>(v1).swap(v1);" << endl;
    cout << "v1 的容量: " << v1.capacity() << endl;
    cout << "v1 的大小: " << v1.size() << endl;

}


int main() {
    test02();
    return 0;
}
```

# 8. vector 预留空间
+ 减少 vector 在动态扩展容量时的扩展次数
+ 函数原型
+ `reserve(int len);` 容器预留 len 个元素长度，预留位置不初始化，元素不可访问

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// vector 容器数据存取
void printVector(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << "  ";
    }
    cout << endl;
}

// vector 容器
void test01() {
    vector<int> v1;

    // 统计开辟次数
    int num = 0;

    int *p = nullptr;

    for (int i = 0; i < 100000; ++i) {
        v1.push_back(i);
        if (p != &v1[0]) {
            p = &v1[0];
            num++;
        }
    }

    cout << "num = " << num << endl;
    cout << "v1 的容量: " << v1.capacity() << endl;
    cout << "v1 的大小: " << v1.size() << endl;
}

void test02() {
    const int s = 100000;

    vector<int> v1;
    v1.reserve(s);

    // 统计开辟次数
    int num = 0;

    int *p = nullptr;

    for (int i = 0; i < s; ++i) {
        v1.push_back(i);
        if (p != &v1[0]) {
            p = &v1[0];
            num++;
        }
    }

    cout << "num = " << num << endl;
    cout << "v1 的容量: " << v1.capacity() << endl;
    cout << "v1 的大小: " << v1.size() << endl;
}

int main() {
    test02();
    return 0;
}
```
