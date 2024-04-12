#include <iostream>
#include <regex>
#include "services/service.h"
#include "data_processing.h"

using namespace std;

/**
 * @brief 员工管理系统的主要功能
 *
 * 此函数是程序的入口点。它显示欢迎消息，然后进入一个无限循环，不断提示用户输入对员工数据执行操作的命令
 *
 * @return 该函数不返回值。当用户退出程序时选择退出系统
 */
int main() {
    cout << ">> 筱锋公司员工信息管理系统 <<" << endl;
    cout << "欢迎使用本系统，系统正在启动中......" << endl;

    while (true) {
        cout << "========================" << endl;
        cout << "1. 员工信息查询" << endl;
        cout << "2. 员工信息录入" << endl;
        cout << "3. 员工信息修改" << endl;
        cout << "4. 员工信息删除" << endl;
        cout << "5. 员工信息统计" << endl;
        cout << "5. 退出系统" << endl;
        // 输入数据
        string input_string;
        cin >> input_string;
        if (regex_match(input_string, regex("^[0-9]+$"))) {
            switch (stoi(input_string)) {
                case 1: {
                    get_vo::user_select get_user_select_vo = processing::select_user();
                    service::user user_service;
                    user_service.get_user(get_user_select_vo);
                    break;
                }
                case 2:
                    selectEmployee();
                    break;
                case 3:
                    updateEmployee();
                    break;
                case 4:
                    deleteEmployee();
                    break;
                case 5:
                    exit(0);
                    break;
                default:
                    break;
            }
        } else {
            cout << "输入错误，请重新输入！" << endl;
        }
    }
}
