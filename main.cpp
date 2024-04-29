#include <iostream>
#include <regex>
#include <mysqlx/xdevapi.h>
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
        cout << "6. 退出系统" << endl;
        cout << "========================" << endl;
        // 输入数据
        std::string input_string;
        cout << "请输入选项: ";
        cin >> input_string;
        if (regex_match(input_string, regex("^[0-9]+$"))) {
            switch (stoi(input_string)) {
                case 1: {
                    // 查询员工信息
                    back_vo::user_info get_user_select_vo = processing::select_user();
                    // 展示用户的信息
                    cout << "员工信息如下：" << endl;
                    cout << "员工编号：" << get_user_select_vo.user_number << endl;
                    cout << "员工姓名：" << get_user_select_vo.user_name << endl;
                    cout << "员工性别：" << get_user_select_vo.user_sex << endl;
                    cout << "员工部门：" << get_user_select_vo.user_department << endl;
                    cout << "员工工资：" << get_user_select_vo.user_wages << endl;
                    cout << "员工级别：" << get_user_select_vo.user_level << endl;
                    break;
                    cout << "[系统] 员工系统查询完成" << endl;
                }
                case 2: {
                    // 添加员工信息
                    if (processing::add_user()) {
                        cout << "[系统] 员工信息添加成功！" << endl;
                    } else {
                        cout << "[系统] 员工信息添加失败！" << endl;
                    }
                    break;
                }
                case 3: {
                    // 修改员工信息
                    if (processing::edit_user()) {
                        cout << "[系统] 员工信息修改成功！" << endl;
                    } else {
                        cout << "[系统] 员工信息修改失败！" << endl;
                    }
                    break;
                }
                case 4: {
                    // 删除员工信息
                    if (processing::delete_user()) {
                        cout << "[系统] 员工信息删除成功！" << endl;
                    } else {
                        cout << "[系统] 员工信息删除失败！" << endl;
                    }
                    break;
                }
                case 5: {
                    // 统计员工信息
                    // processing::statistics_user();
                    break;
                }
                case 6: {
                    // 退出系统
                    cout << "[系统] 感谢您的使用，再见！" << endl;
                    exit(0);
                    break;
                }
                default:
                    // 错误输入
                    break;
            }
        } else {
            cout << "输入错误，请重新输入！" << endl;
        }
    }
}
