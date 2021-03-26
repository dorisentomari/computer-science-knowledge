// 防止头文件重复包含
#pragma once

// 输入输出流的头文件
#include <iostream>
#include "user/worker.h"

// 使用标准命名空间
using namespace std;

class WorkerManager {
public:
    // 记录职工人数
    int m_EmpNum;

    // 职工数组指针
    Worker **m_EmpArray;

    // 标志文件是否为空
    bool m_FileIsEmpty;

    // 构造函数
    WorkerManager();

    // 展示菜单
    void showMenu();

    // 析构函数
    ~WorkerManager();

    // 退出函数
    void exitSystem();

    // 添加员工
    void addEmp();

    // 保存文件
    void save();

    // 统计人数，有文件存在的时候
    int getEmpNum();

    // 初始化职工
    void initEmp();

    // 显示职工
    void showEmp();

    // 删除职工
    void delEmp();

    // 判断职工是否存在
    int isExit(int id);

    // 修改职工
    void modifyEmp();

    // 查找职工
    void findEmp();

    void sortEmp();

    void cleanFile();

};
