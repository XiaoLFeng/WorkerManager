//
// Created by 筱锋 on 24-4-12.
//

#include <iostream>
#include "../config/sql_connect.cpp"
#include "../model/vo/back/user_info.cpp"
#include "../model/vo/get/user_create.cpp"
#include "../model/vo/get/user_select.cpp"
#include "../model/entity/user_do.cpp"
#include "../processing_util.cpp"

using namespace sql;
using namespace util;
using namespace entity;
namespace service {
    class user {
    public:
        bool add_user(const get_vo::user_create &user_info);
        bool edit_user(const get_vo::user_edit &user_info);
        bool delete_user(const std::string number);
        back_vo::user_info get_user(const get_vo::user_select &user_info);
        back_vo::user_info *get_user_by_username(std::string username);
    };
}
