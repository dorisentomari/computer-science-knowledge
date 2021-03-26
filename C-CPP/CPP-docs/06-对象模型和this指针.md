# 1. 成员变量和成员函数分开存储
+ 在 C++ 中，类内的成员变量和成员函数分开存储
+ 只有非静态成员变量才属于类的对象上
+ 一个空对象的大小是 1

```cpp
#include <iostream>

using namespace std;

// 成员变量和成员函数是分开存储的
class Person {
    int a;          // 非静态成员变量，属于类的对象上
    static int b;   // 静态成员变量，不属于类的对象上
    void func();    // 非静态成员函数，不属于类的对象上
    static void func2();     // 静态成员函数，不属于类的对象上
};

void test01() {
    Person p1;
    Person p2;
    // C++ 编译器会给每个空对象分配一个字节的空间，是为了区分空对象占内存的位置
    cout << "sizeof(p1) = " << sizeof(p1) << endl;
    cout << "sizeof(p1) = " << sizeof(p2) << endl;
}

int main() {
    test01();
    return 0;
}
```

# 2. this 指针
+ C++ 中成员变量和成员函数是分开存储的
+ 每一个非静态成员函数只会诞生一份函数示例，也就是说多个同类型对象会共用一块代码
+ 所以问题是：这一块代码如何区分哪个对象调用自己呢？
+ C++ 通过提供特殊的对象指针，this 指针，解决上述问题，**this 指针指向被调用的成员函数所属的对象**
+ this 指针是隐含每一个非静态成员函数内的一种指针
+ this 指针不需要定义，直接使用即可
+ this 指针用途
  + 当形参和成员变量同名时，可以用 this 指针来区分
  + 在类的非静态成员函数宏返回对象本身，可使用 `return *this;`

```cpp
#include <iostream>

using namespace std;

class Person {
public:
    int age = 0;

    Person(int age) {
        this->age = age;
        cout << "this->age = " << this->age << endl;
    }

    Person(const Person &p) {
        cout << "Person 的拷贝构造函数" << endl;
    }


    Person& personAddAge (Person &p) {
        this->age += p.age;
        return *this;
    }
};

int main() {
    Person p1(10);
    Person p2(20);
    p2.personAddAge(p1).personAddAge(p1).personAddAge(p1);
    cout << "p1.age = " << p1.age << endl;
    cout << "p2.age = " << p2.age << endl;
    return 0;
}
```

# 3. 空指针访问成员函数
+ C++ 中空指针也可以调用成员函数，但是要注意有没有用到 this 指针
+ 如果用到 this 指针，需要加以判断保证代码的健壮性

```cpp
#include <iostream>

using namespace std;

class Person {
public:
    int m_Age;


    void showClassName() {
        cout << "我是 Person 类" << endl;
    }

    void showPersonAge() {
        cout << "Person 类的 m_Age = " << this->m_Age << endl;
    }

};

void test01() {
    // 报错的原因是传入的指针为 NULL
    Person *p = NULL;
    if (p == NULL) {
        return;
    }
    p->showClassName();
    p->showPersonAge();
}

int main() {
    test01();
    return 0;
}
```

# 4. const 修饰成员函数
+ 常函数
  + 成员函数后加 const 后我们称之为这个函数为常函数
  + 在常函数内部不可以修改成员属性
  + 成员属性声明时加关键字 mutable 后，在常函数中依然可以修改
+ 常对象
  + 声明对象前加 const 称该对象为常对象
  + 常对象只能调用常函数
+ this 指针的本质是指针常量，指针的指向是不可以修改的
+ 在成员函数后面加 const，修饰的是 this 指向，让指针指向的值不可以修改

```cpp
#include <iostream>

using namespace std;

class Person {
public:
    mutable int m_A;

    void showPerson() const {
        cout << "showPerson m_A = " << this->m_A << endl;
        this->m_A = 100;
        cout << "showPerson m_A = " << this->m_A << endl;
    }
};

void test01() {
    Person p;
    p.showPerson();
}

int main() {
    test01();
    return 0;
}
```

# 5. 友元
+ 在程序里，有一些私有属性，也想让类外特殊的一些函数或者类进行访问，就需要用到友元
+ 友元的目的是为了让一个函数或一个类访问到另外一个类的私有成员
+ 友元的关键字 friend
+ 友元的三种实现
  + 全局函数做友元
  + 类做友元
  + 成员函数做友元

## 5.1 全局函数做友元

```cpp
#include <iostream>
#include <string>

using namespace std;

class Building {
    friend void goodFriend(Building &building);

private:
    string m_BedRoom;
public:
    string m_SittingRoom;

    Building() {
        m_BedRoom = "卧室";
        m_SittingRoom = "客厅";
    }
};

// 全局函数
void goodFriend(Building &building) {
    cout << "全局函数访问: " << building.m_SittingRoom << endl;
    cout << "全局函数访问: " << building.m_BedRoom << endl;
}

void test01() {
    Building building;
    goodFriend(building);
}

int main() {
    test01();
    return 0;
}
```

## 5.2 类做友元

```cpp
#include <iostream>
#include <string>

using namespace std;

// 声明 Building 类
class Building;

class GoodFriend {
public:
    GoodFriend();

    Building *building;

    // 访问 building 的属性
    void visit();
};

class Building {
    friend class GoodFriend;

public:
    string m_SittingRoom;

    Building();

private:
    string m_BedRoom;
};

Building::Building() {
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
    cout << "Building 构造函数" << endl;
}

GoodFriend::GoodFriend() {
    building = new Building;
    cout << "GoodFriend 构造函数" << endl;
}

void GoodFriend::visit() {
    cout << "GoodFriend 正在访问：" << building->m_SittingRoom << endl;
    cout << "GoodFriend 正在访问：" << building->m_BedRoom << endl;
}

void test01() {
    GoodFriend goodFriend;
    goodFriend.visit();
}

int main() {
    test01();
    return 0;
}
```

## 5.3 成员函数做友元
```cpp
#include <iostream>
#include <string>

using namespace std;

class Building;

class GoodFriend {
public:
    Building *building;

    GoodFriend();

    // 让 visit 函数可以访问 Building 的私有成员
    void visit1();

    // 让 visit 函数不可以访问 Building 的私有成员
    void visit2();
};

class Building {
    // 成员函数作为本类的友元来访问属性
    friend void GoodFriend::visit1();
public:
    Building();

public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};

void GoodFriend::visit1() {
    cout << "visit1 正在访问：" << building->m_SittingRoom << endl;
    cout << "visit1 正在访问：" << building->m_BedRoom << endl;
}

void GoodFriend::visit2() {
    cout << "visit2 正在访问：" << building->m_SittingRoom << endl;
//    cout << "visit2 正在访问：" << building->m_BedRoom << endl;
}

Building::Building() {
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

GoodFriend::GoodFriend() {
    building = new Building;
}

void test01() {
    GoodFriend goodFriend;
    goodFriend.visit1();
    goodFriend.visit2();
}

int main() {
    test01();
    return 0;
}

```
