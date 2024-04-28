//
// Created by 筱锋 on 24-4-12.
//

#ifndef WORKERMANAGER_DATA_PROCESSING_H
#define WORKERMANAGER_DATA_PROCESSING_H

#include <iostream>

using namespace std;
namespace processing {
    back_vo::user_info select_user() {
        cout << "========== select_user ==========" << endl;
        cout << "您正在进行员工信息的查询;" << endl;
        cout << "用户的查询可以按姓名、电话号码、工号查询;" << endl;
        cout << "========== select_user ==========" << endl;
        cout << "请输入需要查询的信息：";
        get_vo::user_select user_select_vo;
        cin >> user_select_vo.user;
        service::user user_service;
        return user_service.get_user(user_select_vo);
    }

    bool add_user() {
        get_vo::user_create user_create_vo;
        cout << "========== add_user ==========" << endl;
        cout << "您正在进行员工信息的添加;" << endl;
        cout << "请输入员工的姓名：";
        cin >> user_create_vo.user_name;
        cout << "请输入员工的性别：";
        cin >> user_create_vo.user_sex;
        cout << "请输入员工的部门：";
        cin >> user_create_vo.user_department;
        cout << "请输入员工的工资：";
        cin >> user_create_vo.user_wages;
        cout << "请输入员工的级别：";
        cin >> user_create_vo.user_level;
        cout << "========== add_user ==========" << endl;
        service::user user_service;
        return user_service.add_user(user_create_vo);
    }
    
    bool edit_user() {
        // 请输入您需要修改的员工信息
        back_vo::user_info userInfo = select_user();
        int check_edit = 0;
        // 是否确认修改
        cout << "是否确认修改员工信息？(1 是，2 不是）：";
        cin >> check_edit;
        if (!check_edit) {
            cout << "您已取消修改员工信息!" << endl;
            return false;
        }
        // 开始修改员工信息
        get_vo::user_edit user_edit_vo;
        cout << "========== edit_user ==========" << endl;
        cout << "您正在进行员工 " << userInfo.user << " 信息的修改;" << endl;
        cout << "请输入员工的工号：";
        cin >> user_edit_vo.user_number;
        cout << "请输入员工的姓名：";
        cin >> user_edit_vo.user_name;
        cout << "请输入员工的性别：";
        cin >> user_create_v
    }
    
}

#endif //WORKERMANAGER_DATA_PROCESSING_H
