#pragma once

#include <iostream>
#include <string>

using namespace std;

class Worker{
public:
    // 显示个人信息
    virtual void showInfo() = 0;

    // 获取岗位名称
    virtual string getDeptName () = 0;

    // 职工编号
    int m_Id;

    // 职工姓名
    string m_Name;

    // 职工所在的部门名称编号
    int m_DeptId;
};
