//
// Created by 筱锋 on 24-4-12.
//

#include <iostream>
#include "../vo/back/user_info.cpp"
#include "../vo/get/user_create.cpp"
#include "../vo/get/user_select.cpp"

namespace service {
    class user {
    public:
        bool add_user(const get_vo::user_create &user_info);
        back_vo::user_info get_user(const get_vo::user_select &user);
    };
}
