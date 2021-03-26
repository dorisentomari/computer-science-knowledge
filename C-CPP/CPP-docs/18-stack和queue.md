# 1. stack 基本概念
+ stack 是一种先进后出的数据结构，只有一个出口
+ 栈中只有顶端的元素才可以被外界使用，因为栈不允许有遍历操作

# 2. stack 常用接口
## 2.1 构造函数
+ `stack<T> stk;` stack 采用模板类实现，stack 对象的默认构造形式
+ `stack(const stack &stk);` 拷贝构造函数

## 2.2 赋值操作
+ `stack& operator=(const stack &stk);` 重载等号操作符

## 2.3 数据存储
+ `push(elem);` 入栈，往栈顶添加元素
+ `pop();` 出栈，从栈顶移除元素
+ `top();` 返回栈顶元素

## 2.4 大小操作
+ `empty();` 判断栈堆是否为空
+ `size();` 返回栈的大小

```cpp
#include <iostream>
#include <stack>

using namespace std;

void test01() {
    stack<int> stk;

    stk.push(100);
    stk.push(200);
    stk.push(300);
    stk.push(400);

    while (!stk.empty()) {
        cout << "栈顶元素 = " << stk.top() << endl;
        stk.pop();
        cout << "栈的大小 = " << stk.size() << endl;
    }

}

int main() {
    test01();
    return 0;
}
```

# 3. queue 基本概念
+ 队列，先进先出的数据结构，有两个出口
+ 队列容器允许从一端新增元素，从另一端移除元素
+ 队列中只有队头和队尾才可以被外界访问，因此队列不允许有遍历操作
+ 队列中进数据称为入队 push
+ 队列中出数据称为出队 pop

# 4. queue 常用接口
## 4.1 构造函数
+ `queue<T> que;` queue 采用模板类实现，queue 对象的默认构造形式
+ `queue(const queue &que);` 拷贝构造函数

## 2.2 赋值操作
+ `queue& operator=(const queue &que);` 重载等号操作符

## 2.3 数据存储
+ `push(elem);` 入队，往队尾添加元素
+ `pop();` 出队，从队头移除元素
+ `back();` 返回最后一个元素
+ `front();` 返回第一个元素

## 2.4 大小操作
+ `empty();` 判断队列是否为空
+ `size();` 返回队列的大小

```cpp
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Person {
public:
    string m_Name;
    int m_Age;

    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }
};


void test01() {
    // 创建队列
    queue<Person> que;

    // 准备数据
    Person p1("Sherry", 19);
    Person p2("Tom", 20);
    Person p3("Jack", 20);
    Person p4("Marry", 18);

    // 入队
    que.push(p1);
    que.push(p2);
    que.push(p3);
    que.push(p4);
    cout << "队列的大小 = " << que.size() << endl;
    // 只要队列不为空，查看队头，查看队尾
    while (!que.empty()) {
        cout << "队头元素姓名 = " << que.front().m_Name << "   队头元素年龄 = " << que.front().m_Age << endl;
        cout << "队尾元素姓名 = " << que.back().m_Name << "   队尾元素年龄 = " << que.back().m_Age << endl;
        que.pop();
        cout << "队列的大小 = " << que.size() << endl;
    }


}

int main() {
    test01();
    return 0;
}
```
