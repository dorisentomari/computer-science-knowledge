#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

Employee::Employee(int id, string name, int dId) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Employee::showInfo() {
    cout << "职工编号： " << this->m_Id
         << "\t职工姓名： " << this->m_Name
         << "\t职工岗位： " << this->getDeptName()
         << "\t岗位职责： " << "完成经理交给的任务" << endl;
}

string Employee::getDeptName() {
    return string("普通员工");
}
