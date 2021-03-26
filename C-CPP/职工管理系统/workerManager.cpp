#include <iostream>
#include <fstream>

#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define FILENAME "empFile.txt"

WorkerManager::WorkerManager() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    // case 1 文件不存在
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = nullptr;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    // case 2 文件存在但是文件内容为空
    if (ifs.eof()) {
        cout << "文件存在但是记录为空" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = nullptr;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    // case 3 文件存在且有内容
    this->m_EmpNum = this->getEmpNum();
    this->initEmp();
    this->m_FileIsEmpty = false;
}

WorkerManager::~WorkerManager() {
    if (this->m_EmpArray != nullptr) {
        delete[] this->m_EmpArray;
        this->m_EmpArray = nullptr;
    }
}

void WorkerManager::showMenu() {
    cout << "*********************************************" << endl;
    cout << "**********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0. 退出管理程序 **************" << endl;
    cout << "*************  1. 增加职工信息 **************" << endl;
    cout << "*************  2. 显示职工信息 **************" << endl;
    cout << "*************  3. 删除离职职工 **************" << endl;
    cout << "*************  4. 修改职工信息 **************" << endl;
    cout << "*************  5. 查找职工信息 **************" << endl;
    cout << "*************  6. 按照编号排序 **************" << endl;
    cout << "*************  7. 清空所有文档 **************" << endl;
    cout << "*********************************************" << endl;
    cout << endl;
}

void WorkerManager::exitSystem() {
    cout << "欢迎下次使用!" << endl;
    system("pause");
    // 退出程序
    exit(0);
}

void WorkerManager::addEmp() {
    cout << "请输入增加职工数量： " << endl;
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0) {
        // 计算新空间大小
        int newSize = this->m_EmpNum + addNum;

        // 开辟新空间
        Worker **newSpace = new Worker *[newSize];

        // 将原空间下内容存放到新空间下
        if (this->m_EmpArray != nullptr) {
            for (int i = 0; i < this->m_EmpNum; ++i) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        for (int i = 0; i < addNum; ++i) {
            int id;
            string name;
            int dSelect;

            cout << "请输入第 " << i + 1 << " 个新职工编号" << endl;
            cin >> id;

            cout << "请输入第 " << i + 1 << " 个新职工姓名" << endl;
            cin >> name;

            cout << "请选择该职工的岗位： " << endl;
            cout << "1、普通员工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            Worker *worker = nullptr;

            switch (dSelect) {
                case 1:
                    worker = new Employee(id, name, dSelect);
                    break;
                case 2:
                    worker = new Manager(id, name, dSelect);
                    break;
                case 3:
                    worker = new Boss(id, name, dSelect);
                    break;
                default:
                    break;
            }

            newSpace[this->m_EmpNum + i] = worker;

        }

        // 释放原有空间
        //  delete[] this->m_EmpArray;

        // 更改新空间的指向
        this->m_EmpArray = newSpace;

        // 更新新的个数
        this->m_EmpNum = newSize;

        // 提示信息
        cout << "成功添加 " << addNum << " 名新职工" << endl;

        // 保存文件
        this->save();

        this->m_FileIsEmpty = true;

    } else {
        cout << "输入有误" << endl;
    }

//    system("pause");
//    system("cls");
}

void WorkerManager::save() {
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->m_EmpNum; ++i) {
        Worker *m_TempEmpArray = this->m_EmpArray[i];
        ofs << m_TempEmpArray->m_Id << " "
            << m_TempEmpArray->m_Name << " "
            << m_TempEmpArray->m_DeptId << endl;
    }

    ofs.close();
}

int WorkerManager::getEmpNum() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId) {
        num++;
    }

    ifs.close();

    return num;
}

void WorkerManager::initEmp() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;

    while (ifs >> id && ifs >> name && ifs >> dId) {
        Worker *worker = nullptr;

        if (dId == 1) {
            worker = new Employee(id, name, dId);
        } else if (dId == 2) {
            worker = new Manager(id, name, dId);
        } else {
            worker = new Boss(id, name, dId);
        }

        this->m_EmpArray[index] = worker;

        index++;
    }

    ifs.close();
}

void WorkerManager::showEmp() {
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或者记录为空" << endl;
        return;
    }
    for (int i = 0; i < this->m_EmpNum; ++i) {
        // 利用多态调用程序接口
        this->m_EmpArray[i]->showInfo();
    }

}

void WorkerManager::delEmp() {
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或者记录为空" << endl;
        return;
    }

    cout << "请输入要删除的职工编号：" << endl;
    int id = -1;
    cin >> id;
    int index = this->isExit(id);

    // 职工存在，所以可以删除该员工
    if (index != -1) {
        for (int i = index; i < this->m_EmpNum - 1; ++i) {
            this->m_EmpArray[i] = this->m_EmpArray[i + 1];
        }
        this->m_EmpArray[this->m_EmpNum] = nullptr;
        this->m_EmpNum--;
        this->save();
        cout << "id 为 " << id << "的职工删除成功" << endl;
    } else {
        cout << "id 为 " << id << "的职工不存在" << endl;
    }
}

int WorkerManager::isExit(int id) {
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; ++i) {
        if (this->m_EmpArray[i]->m_Id == id) {
            index = i;
            break;
        }
    }
    return index;
}

void WorkerManager::modifyEmp() {
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或者记录为空" << endl;
        return;
    }

    cout << "请输入修改职工的编号： " << endl;
    int id = -1;
    cin >> id;
    int index = this->isExit(id);

    // 职工存在，所以可以删除该员工
    if (index != -1) {
        delete this->m_EmpArray[index];

        int newId = 0;
        string newName;
        int dSelect = 0;

        cout << "查到 id 为 " << id << "的职工，请输入新职工号：" << endl;
        cin >> newId;

        cout << "请输入新姓名： " << endl;
        cin >> newName;
        cout << "请选择该职工的岗位： " << endl;
        cout << "1、普通员工" << endl;
        cout << "2、经理" << endl;
        cout << "3、老板" << endl;
        cin >> dSelect;

        Worker *worker = nullptr;

        switch (dSelect) {
            case 1:
                worker = new Employee(newId, newName, dSelect);
                break;
            case 2:
                worker = new Manager(newId, newName, dSelect);
                break;
            case 3:
                worker = new Boss(newId, newName, dSelect);
                break;
            default:
                break;
        }

        this->m_EmpArray[index] = worker;

        // 提示信息
        cout << "成功修改 " << newName << " 为新职工" << endl;

        // 保存文件
        this->save();

    } else {
        cout << "id 为 " << id << "的职工不存在" << endl;
    }
}

void WorkerManager::findEmp() {
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或者记录为空" << endl;
        return;
    }

    cout << "请选择查找方式：" << endl;
    cout << "1. 按编号查找" << endl;
    cout << "2. 按照姓名查找" << endl;

    int select = 0;
    cin >> select;

    if (select == 1) {
        int id;
        cout << "请输入查找的职工编号: " << endl;
        cin >> id;
        int index = this->isExit(id);
        if (index != -1) {
            cout << "查找成功！职工信息如下： " << endl;
            this->m_EmpArray[index]->showInfo();
        } else {
            cout << "查找失败，没有此人" << endl;
        }
    } else {
        string name;
        cout << "请输入查找的职工姓名: " << endl;
        cin >> name;

        bool flag = false;
        for (int i = 0; i < this->m_EmpNum; ++i) {
            if (this->m_EmpArray[i]->m_Name == name) {
                cout << "查找成功！职工编号为 " << this->m_EmpArray[i]->m_Id << " 的信息如下：" << endl;
                this->m_EmpArray[i]->showInfo();
                flag = true;
            }
        }
        if (!flag) {
            cout << "查找失败，没有此人" << endl;
        }
    }
}

void WorkerManager::sortEmp() {
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或者记录为空" << endl;
        return;
    }

    cout << "请选择排序方式：" << endl;
    cout << "1. 按职工工号进行升序" << endl;
    cout << "2. 按职工工号进行降序" << endl;

    int select = 0;
    cin >> select;

    for (int i = 0; i < this->m_EmpNum; ++i) {
        int minOrMax = i;
        for (int j = i + 1; j < this->m_EmpNum; ++j) {
            if (select == 1) {
                if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id) {
                    minOrMax = j;
                }
            } else {
                if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id) {
                    minOrMax = j;
                }
            }
        }

        if (i != minOrMax) {
            Worker *temp = this->m_EmpArray[i];
            this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
            this->m_EmpArray[minOrMax] = temp;
        }
    }

    cout << "排序成功，排序后的结果为： " << endl;
    this->save();
    this->showEmp();

}

void WorkerManager::cleanFile() {
    cout << "确认清空？：" << endl;
    cout << "1. 确认" << endl;
    cout << "2. 返回" << endl;
    int select;
    cin >> select;

    if (select == 1) {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if (this->m_EmpArray != nullptr) {
            for (int i = 0; i < this->m_EmpNum; ++i) {
                if (this->m_EmpArray[i] != nullptr) {
                    this->m_EmpArray[i] = nullptr;
                }
            }
            delete[] this->m_EmpArray;
            this->m_EmpArray = nullptr;
            this->m_EmpNum = 0;
            this->m_FileIsEmpty = true;
        }
        cout << "员工记录已清空" << endl;
    } else {
        cout << "取消清空记录" << endl;
    }
}
