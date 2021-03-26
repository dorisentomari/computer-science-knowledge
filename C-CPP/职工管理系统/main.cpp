#include <iostream>

#include "workerManager.cpp"
#include "employee.cpp"
#include "manager.cpp"
#include "boss.cpp"

using namespace std;

int main() {
    // 实例化管理者对象
    WorkerManager wm;

    // 用来存储用户的选项
    int choice;

    while (true) {
        wm.showMenu();
        cout << "请输入您的选择：" << endl;
        // 接收用户的选择
        cin >> choice;

        switch (choice) {
            // 退出系统
            case 0:
                wm.exitSystem();
                break;

                // 添加职工
            case 1:
                cout << "添加职工" << endl;
                wm.addEmp();
                break;

                // 显示职工
            case 2:
                cout << "显示职工" << endl;
                wm.showEmp();
                break;

                // 删除职工
            case 3:
                cout << "删除职工" << endl;
                wm.delEmp();
                break;

                // 修改职工
            case 4:
                cout << "修改职工" << endl;
                wm.modifyEmp();
                break;

                // 查找职工
            case 5:
                cout << "查找职工" << endl;
                wm.findEmp();
                break;

                // 排序员工
            case 6:
                cout << "排序员工" << endl;
                wm.sortEmp();
                break;

                // 清空文档
            case 7:
                cout << "清空文档" << endl;
                wm.cleanFile();
                break;
            default:
                // 清屏操作
                system("cls");
                break;
        }
    }

    return 0;
}
