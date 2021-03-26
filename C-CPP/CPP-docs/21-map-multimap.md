# 1. map 基本概念
+ map 中所有元素都是 pair
+ pair 中第一个元素为 key，起到索引作用，第二个元素为 value
+ 所有元素都会根据元素的键值自动排序
+ 本质：map/multimap 属于关联式容器，底层结构是用二叉树实现
+ 优点：可以根据 key 值快速找到 value 值
+ map 和 multimap 的区别
  + map 不允许容器中有重复的 key 值元素
  + multimap 允许容器中有重复的 key 值元素

# 2. map 构造和赋值
+ 函数原型
+ `map<T1, T2> mp;` map 默认构造函数
+ `map(const map &mp);` 拷贝构造函数
+ `map& operator=(const map &mp);` 重载等号操作符

```cpp
#include <iostream>
#include <string>
#include <map>

using namespace std;

void printMap(map<string, int> &mp) {
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << "key = " << (*it).first << "  value = " << (*it).second << endl;
    }
}

void test01() {
    map<string, int> mp;

    mp.insert(pair<string, int>("Sherry", 19));
    mp.insert(pair<string, int>("Mark", 20));
    mp.insert(pair<string, int>("Jack", 21));
    mp.insert(pair<string, int>("Tom", 22));

    printMap(mp);

    map<string, int> mp2(mp);
    printMap(mp2);

    map<string, int> mp3;
    mp3 = mp;
    printMap(mp3);
}

int main() {
    test01();
    return 0;
}
```

# 3. map 大小和交换
+ 函数原型
+ `empty();` 判断容器是否为空
+ `size();` 返回容器中元素的个数
+ `swap(st);` 交换两个集合容器

```cpp
#include <iostream>
#include <string>
#include <map>

using namespace std;

void printMap(map<string, int> &mp) {
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << "key = " << (*it).first << "  value = " << (*it).second << endl;
    }
}

void test01() {
    map<string, int> mp;

    mp.insert(pair<string, int>("Sherry", 19));
    mp.insert(pair<string, int>("Mark", 20));
    mp.insert(pair<string, int>("Jack", 21));
    mp.insert(pair<string, int>("Tom", 22));
    printMap(mp);

    cout << "mp.size() = " << mp.size() << endl;
    cout << "mp.empty() = " << mp.empty() << endl;

    map<string, int> mp2;
    mp2.insert(pair<string, int>("Monika", 21));
    mp2.insert(pair<string, int>("Well", 22));

    cout << "-------- 交换前 mp ---------" << endl;
    printMap(mp);
    cout << "-------- 交换前 mp2 ---------" << endl;
    printMap(mp2);

    mp.swap(mp2);

    cout << "-------- 交换后 mp ---------" << endl;
    printMap(mp);
    cout << "-------- 交换后 mp2 ---------" << endl;
    printMap(mp2);
}

int main() {
    test01();
    return 0;
}
```

# 4. map 插入和删除
+ 函数原型
+ `insert(elem);` 在容器中插入元素
+ `clear();` 清除所有元素
+ `erase(pos);` 删除 pos 迭代器所指的元素，返回下一个元素的迭代器
+ `erase(begin, end);` 删除区间 `[begin, end]` 的所有元素，返回下一个元素的迭代器
+ `erase(key);` 删除容器中值为 key 的元素

```cpp
#include <iostream>
#include <string>
#include <map>

using namespace std;

void printMap(map<string, int> &mp) {
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << "key = " << (*it).first << "  value = " << (*it).second << endl;
    }
}

void test01() {
    map<string, int> mp;

    // 四种插入方式
    mp.insert(pair<string, int>("Sherry", 19));
    mp.insert(make_pair<string, int>("Mark", 20));
    mp.insert(map<string, int>::value_type("Jack", 21));
    mp["Monika"] = 22;

    mp.clear();
    printMap(mp);

    mp["Monika"] = 22;
    printMap(mp);

    // 清空
    mp.clear();
    printMap(mp);

    // 清空
    mp.erase(mp.begin(), mp.end());
    printMap(mp);
}

int main() {
    test01();
    return 0;
}
```

# 5. map 查找和统计
+ 函数原型
+ `find(key);` 查找 key 是否存在，若存在，返回该键的元素的迭代器，若不存在，返回 set.end()
+ `count(key);` 统计 key 元素的个数，multimap 的 count 统计可能大于 1

```cpp
#include <iostream>
#include <string>
#include <map>

using namespace std;

void printMap(map<string, int> &mp) {
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << "key = " << (*it).first << "  value = " << (*it).second << endl;
    }
}

void test01() {
    map<string, int> mp;

    // 四种插入方式
    mp.insert(pair<string, int>("Sherry", 19));
    mp.insert(make_pair<string, int>("Mark", 20));
    mp.insert(map<string, int>::value_type("Jack", 21));
    mp["Monika"] = 22;

    // 查找
    map<string, int>::iterator pos = mp.find("Jack");
    if (pos != mp.end()) {
        cout << "查找到该元素 = " << (*pos).first << "  " << (*pos).second << endl;

    } else {
        cout << "没有查找到该元素" << endl;
    }

    int num = mp.count("Jack");
    cout << num << endl;
}

int main() {
    test01();
    return 0;
}
```

# 6. map 容器排序
+ 利用仿函数，改变排序规则
+ 自定义数据类型，map 必须要指定排序规则

```cpp
#include <iostream>
#include <string>
#include <map>

using namespace std;

void printMap(map<string, int> &mp) {
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << "key = " << (*it).first << "  value = " << (*it).second << endl;
    }
}

class MapCompare {
public:
    bool operator()(int v1, int v2) {
        return v2 < v1;
    }
};


void test01() {
    map<int, int, MapCompare> m;
    m.insert(make_pair(2, 18));
    m.insert(make_pair(6, 19));
    m.insert(make_pair(4, 21));
    m.insert(make_pair(3, 17));
    m.insert(make_pair(1, 19));
    m.insert(make_pair(5, 22));

    for (map<int, int, MapCompare>::iterator it = m.begin(); it != m.end(); it++) {
        cout << (*it).first << "  " << (*it).second << endl;
    }

}

int main() {
    test01();
    return 0;
}
```

# 7. 员工分组案例
## 7.1 案例描述
+ 公司招聘了 10 个员工(ABCDEFGHIJ)，10 名员工进入公司后，需要指派员工在哪个部门工作
+ 员工信息有：姓名、工资组成。部门分为：策划、美术、研发
+ 随机给 10 名员工分配部门和工资
+ 通过 multimap 进行信息的插入 key(部门编号)，value(员工)
+ 分部门显示员工信息

## 7.2 实现步骤
+ 创建 10 名员工，放到 vector 中
+ 遍历 vector 容器，取出每个员工，进行随机分组
+ 分组后，将员工部门编号作为 key，具体员工作为 value，放入到 multimap 容器中
+ 分部门显示员工信息

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

using namespace std;

class Worker {
public:
    string m_Name;
    int m_Salary;
};

void printMap(map<string, Worker> &mp) {
    for (map<string, Worker>::iterator it = mp.begin(); it != mp.end(); it++) {

    }
}

void createVWorker(vector<Worker> &v) {
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; ++i) {
        Worker worker;
        worker.m_Name = nameSeed[i];
        worker.m_Salary = rand() % 10000 + 10000;   // 10000~19999
        v.push_back(worker);
    }
}

void setGroup(vector<Worker> &v, multimap<int, Worker> &m) {
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
        cout << (*it).m_Name << "  " << (*it).m_Salary << endl;
        // 产生一个随机部门的编号
        int deptId = rand() % 3;
        // 将员工插入到分组中
        m.insert(make_pair(deptId, *it));
    }
}

void showWorkerByGroup(multimap<int, Worker> &m) {
    cout << "策划部门信息" << endl;
    multimap<int, Worker>::iterator pos = m.find(CEHUA);

    int count = m.count(CEHUA);
    int index = 0;
    for (; pos != m.end() && index < count; pos++, index++) {
        cout << "姓名 = " << pos->second.m_Name << "  工资 = " << pos->second.m_Salary << endl;
    }

    cout << "美术部门信息" << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU);
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++) {
        cout << "姓名 = " << pos->second.m_Name << "  工资 = " << pos->second.m_Salary << endl;
    }

    cout << "研发部门信息" << endl;
    pos = m.find(YANFA);
    count = m.count(YANFA);
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++) {
        cout << "姓名 = " << pos->second.m_Name << "  工资 = " << pos->second.m_Salary << endl;
    }

}

void test01() {
    srand((unsigned int) time(nullptr));
    // 1. 创建员工
    vector<Worker> vWorker;
    createVWorker(vWorker);

    // 2. 员工分组
    multimap<int, Worker> mWorker;
    setGroup(vWorker, mWorker);

    // 3. 分组显示员工
    showWorkerByGroup(mWorker);

}

int main() {
    test01();
    return 0;
}
```


