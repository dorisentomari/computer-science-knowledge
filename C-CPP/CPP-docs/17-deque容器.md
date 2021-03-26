# 1. deque 容器基本概念
+ 功能：双端数组，可以对头端进行插入删除操作
+ deque 和 vector 区别
  + vector 对于头部的插入删除效率较低，数据量越大，效率越低
  + deque 相对而言，对头部的插入删除速度会比 vector 快
  + vector 访问元素时的速度比 deque 快，这和两者的内部实现有关
+ deque 内部工作原理
  + deque 内部有一个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
  + 中控器维护的是每个缓冲区的地址，使得使用 deque 时像一片连续的内存空间
+ deque 容器的迭代器时支持随机访问的

# 2. deque 构造函数
+ 函数原型
+ `deque<T> deqT;` 默认构造形式
+ `deque(beg, end);` 构造函数将 `[beg, end]` 区间中的元素拷贝给本身
+ `deque(n, elem);` 构造函数将 n 个 elem 拷贝给本身
+ `deque(const deque & deq);` 拷贝构造函数

```cpp
#include <iostream>
#include <string>
#include <deque>

using namespace std;

// 使用 const 修饰，容器内部数据不可以修改
void printDeque(const deque<int> &d) {
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        // *it = 100;
        cout << *it << " ";
    }
    cout << endl;
}

// deque 容器
void test01() {
    deque<int> d1;

    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }

    printDeque(d1);

    deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);

    deque<int> d3(10, 100);
    printDeque(d3);

    deque<int> d4(d3);
    printDeque(d4);

}

int main() {
    test01();
    return 0;
}
```

# 3. deque 赋值操作
+ 函数原型
+ `deque& operator=(const deque &deq);`  重载等号操作符
+ `assign(begin, end);` 将 `[begin, end]` 区间中的数据拷贝赋值给本身
+ `assign(n, elem);` 将 n 个 elem 拷贝赋值给本身

```cpp
#include <iostream>
#include <string>
#include <deque>

using namespace std;

// 使用 const 修饰，容器内部数据不可以修改
void printDeque(const deque<int> &d) {
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        // *it = 100;
        cout << *it << " ";
    }
    cout << endl;
}

// deque 容器
void test01() {
    deque<int> d1;

    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }

    printDeque(d1);

    deque<int> d2;
    d2.assign(d1.begin(), d1.end());
    printDeque(d2);

    deque<int> d3;
    d3.assign(10, 100);
    printDeque(d3);

}

int main() {
    test01();
    return 0;
}
```

# 4. deque 容量和大小
+ 函数原型
+ `deque.empty();` 判断容器是否为空
+ `deque.size();` 返回容器中元素的个数
+ `deque.resize(int num);` 重新指定容器的长度为 num，若容器变长，则以默认值 0 填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
+ `deque.resize(int num, elem);` 重新指定容器的长度为 num，若容器变长，则以 elem 填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
+ 总结：
  + deque 没有 capacity，可以无限扩展，扩展的时候只需要在中控器添加就可以

```cpp
#include <iostream>
#include <string>
#include <deque>

using namespace std;

// 使用 const 修饰，容器内部数据不可以修改
void printDeque(const deque<int> &d) {
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        // *it = 100;
        cout << *it << " ";
    }
    cout << endl;
}

// deque 容器
void test01() {
    deque<int> d1;

    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }

    printDeque(d1);

    cout << "d1.empty() = " << d1.empty() << endl;
    cout << "d1.size() = " << d1.size() << endl;

    d1.resize(20);
    printDeque(d1);

    d1.resize(10, 2);
    printDeque(d1);
}

int main() {
    test01();
    return 0;
}
```

# 5. deque 插入和删除

## 5.1 两端插入操作
+ `push_back(elem);` 在容器尾部添加一个数据
+ `push_front(elem);` 在容器头部添加一个数据
+ `pop_back();` 删除容器最后一个数据
+ `pop_front();` 删除容器第一个数据

## 5.2 指定位置操作
+ `insert(pos, elem);` 在 pos 位置插入一个 elem 元素的拷贝，新数据的位置
+ `insert(pos, n, elem);` 在 pos 位置插入 n 个 elem 数据，无返回值
+ `insert(pos, begin, end);` 在 pos 位置插入 `[begin, end]` 区间的数据，无返回值
+ `clear();` 清空容器的所有数据
+ `erase(begin, end);` 删除 `[begin, end]` 区间的数据，返回下一个数据的位置
+ `erase(pos);` 删除 pos 位置的数据，返回下一个数据的位置

```cpp
#include <iostream>
#include <string>
#include <deque>

using namespace std;

// 使用 const 修饰，容器内部数据不可以修改
void printDeque(const deque<int> &d) {
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        // *it = 100;
        cout << *it << " ";
    }
    cout << endl;
}

// deque 容器插入和删除
void test01() {
    deque<int> d1;

    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);

    printDeque(d1);

    d1.pop_back();
    d1.pop_front();
    printDeque(d1);

}

void test02() {
    deque<int> d1;

    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);

    d1.insert(d1.begin(),30);
    printDeque(d1);

    d1.insert(d1.begin(), 2, 2000);
    printDeque(d1);

    d1.clear();
    printDeque(d1);

    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);

}

int main() {
    test02();
    return 0;
}
```

# 6. deque 数据存取
+ 函数原型
+ `at(int idx);` 返回索引 idx 所指的数据
+ `operator[];` 返回索引 idx 所指的数据
+ `front();` 返回容器中的第一个数据元素
+ `back();` 返回容器中的最后一个数据元素

```cpp
#include <iostream>
#include <string>
#include <deque>

using namespace std;

// 使用 const 修饰，容器内部数据不可以修改
void printDeque(const deque<int> &d) {
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        // *it = 100;
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    deque<int> d1;
    for(int i = 0; i < 10; i++) {
        d1.push_back(i);
    }

    for (int i = 0; i < d1.size(); ++i) {
        cout << "d1.at(" << i << ") = " << d1.at(i) << endl;
        cout << "d1[" << i << "] = " << d1.at(i) << endl;
    }

    cout << "d1.front() = " << d1.front() << endl;
    cout << "d1.back() = " << d1.back() << endl;

}

int main() {
    test01();
    return 0;
}
```

# 7. deque 排序操作
+ 算法: `sort(iterator begin, iterator end);` 对 begin 和 end 区间内元素进行排序
+ 对于支持随机访问的迭代器的容器，都可以利用 sort 算法直接对其进行排序

```cpp
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

// 使用 const 修饰，容器内部数据不可以修改
void printDeque(const deque<int> &d) {
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        // *it = 100;
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    deque<int> d1;
    d1.push_back(1);
    d1.push_back(2);
    d1.push_front(3);
    d1.push_front(4);
    printDeque(d1);

    sort(d1.begin(), d1.end());
    printDeque(d1);
}

int main() {
    test01();
    return 0;
}
```

# 8. 评委打分案例
+ 案例描述：有 5 名选手 ABCDE，10 个评委分别对每一名选手打分，去除最高分，去除最低分，取平均分
+ 实现步骤
  + 创建五名选手，放入 vector 中
  + 遍历 vector 容器，取出来每一个选手，执行 for 循环，可以把 10 个打分存到 deque 容器
  + sort 算法对 deque 容器中分数排序，去除最高分和最低分
  + deque 容器遍历一遍，累计加分
  + 获取平均分

```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <ctime>

using namespace std;

class Person {
public:
    string m_Name;
    int m_Score;

    Person(string name, int score) {
        this->m_Name = name;
        this->m_Score = score;
    }
};

void createPerson(vector<Person> &v) {
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; ++i) {
        string name = "选手";
        name += nameSeed[i];
        v.push_back(Person(name, 0));
    }
}

void setScore(vector<Person> &v) {
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
        // 将评委分数放入 deque 中
        deque<int> d;
        for (int i = 0; i < 10; ++i) {
            int score = rand() % 41 + 60;
            d.push_back(score);
        }

        sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();

        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
            sum += *dit;
        }
        int avg = sum / d.size();
        it->m_Score = avg;
    }
}

void test01() {
    // 添加随机种子
    srand((unsigned int)time(nullptr));
    // 1. 创建 5 名选手
    vector<Person> v;
    createPerson(v);

    // 2. 给 5 名选手打分
    setScore(v);

    // 3. 显示最后得分
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
        cout << (*it).m_Name << " " << (*it).m_Score << endl;
    }

}

int main() {
    test01();
    return 0;
}
```

