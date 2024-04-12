//
// Created by 筱锋 on 24-4-12.
//

#ifndef WORKERMANAGER_DATA_PROCESSING_H
#define WORKERMANAGER_DATA_PROCESSING_H
#include <iostream>
#include "vo/get/user_select.cpp"

using namespace std;
namespace processing {
    get_vo::user_select select_user() {
        cout << "========== select_user ==========" << endl;
        cout << "您正在进行员工信息的查询;" << endl;
        cout << "用户的查询可以按姓名、电话号码、工号查询;" << endl;
        cout << "========== select_user ==========" << endl;
        cout << "请输入需要查询的信息：";
        get_vo::user_select user_create_vo;
        cin >> user_create_vo.user;
        return user_create_vo;
    }
}

#endif //WORKERMANAGER_DATA_PROCESSING_H
