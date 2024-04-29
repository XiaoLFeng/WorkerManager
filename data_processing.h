//
// Created by 筱锋 on 24-4-12.
//

#ifndef WORKERMANAGER_DATA_PROCESSING_H
#define WORKERMANAGER_DATA_PROCESSING_H

#include <iostream>

using namespace std;
namespace processing {

    // 跳入员工信息的查询
    // 该方法用于查询员工信息
    // 返回值为员工信息
    // 该方法会调用 get_user 方法
    void select_user() {
        cout << "========== select_user ==========" << endl;
        cout << "您正在进行员工信息的查询;" << endl;
        cout << "用户的查询可以按姓名、电话号码、工号查询;" << endl;
        cout << "========== select_user ==========" << endl;
        cout << "请输入需要查询的信息：";
        get_vo::user_select user_select_vo;
        cin >> user_select_vo.user;
        service::user::get_user(user_select_vo);
    }

    // 添加员工信息
    // 该方法用于添加员工信息
    // 返回值为是否添加成功
    // 该方法会调用 add_user 方法
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
        cout << "请输入员工职位：";
        cin >> user_create_vo.user_position;
        cout << "========== add_user ==========" << endl;
        service::user user_service;
        return user_service.add_user(&user_create_vo);
    }

    // 修改员工信息
    // 该方法用于修改员工信息
    // 返回值为是否修改成功
    // 该方法会调用 select_user 方法
    bool edit_user() {
        // 请输入您需要修改的员工信息
        auto *userInfo = new back_vo::user_info;
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
        cout << "您正在进行员工 [" << userInfo->user_number << "]" << userInfo->user_name << " 信息的修改;" << endl;
        cout << "请输入员工的工号：";
        cin >> user_edit_vo.user_number;
        cout << "请输入员工的姓名：";
        cin >> user_edit_vo.user_name;
        cout << "请输入员工的部门：";
        cin >> user_edit_vo.user_department;
        cout << "请输入员工的工资：";
        cin >> user_edit_vo.user_wages;
        cout << "请输入员工的级别：";
        cin >> user_edit_vo.user_level;
        cout << "请输入员工的职位：";
        cin >> user_edit_vo.user_position;
        cout << "========== edit_user ==========" << endl;
        service::user user_service;
        return user_service.edit_user(user_edit_vo);
    }

    // 删除员工信息
    // 该方法用于删除员工信息
    // 返回值为是否删除成功
    // 该方法会调用 select_user 方法
    bool delete_user() {
        // 请输入您需要删除的员工信息
        cout << "========== delete_user ==========" << endl;
        cout << "您正在进行员工信息的删除;" << endl;
        std::string userName;
        cout << "请输入员工的姓名：";
        cin >> userName;
        cout << "========== delete_user ==========" << endl;
        service::user user_service;
        back_vo::user_info *userInfo = user_service.get_user_by_username(userName);
        if (userInfo != nullptr) {
            int check_delete = 0;
            // 是否确认删除
            cout << "是否确认删除员工信息？(1 是，0 不是）：";
            cin >> check_delete;
            if (check_delete) {
                cout << "您已取消删除员工信息!" << endl;
                return false;
            }
            // 开始删除员工信息
            return user_service.delete_user(userInfo->user_number);
        } else {
            cout << "未找到员工信息！" << endl;
            return false;
        }
    }
    
}
#endif //WORKERMANAGER_DATA_PROCESSING_H
