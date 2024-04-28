//
// Created by 筱锋 on 24-4-12.
//

#include <iostream>
#include "../config/sql_connect.cpp"
#include "../vo/back/user_info.cpp"
#include "../vo/get/user_create.cpp"
#include "../vo/get/user_select.cpp"
#include "../processing_util.cpp"

using namespace sql;
using namespace util;
namespace service {
    class user {
    public:
        bool add_user(const get_vo::user_create &user_info);
        back_vo::user_info get_user(const get_vo::user_select &user_info);
    };
}
