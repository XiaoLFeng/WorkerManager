//
// Created by 筱锋 on 24-4-12.
//

#include "service.h"

// add_user 方法实现
// 该方法用于添加用户信息
bool service::user::add_user(const get_vo::user_create &user_info) {
    // 对用户的信息进行检查
    if (user_info.user_number.empty()) {
        std::cout << "[服务] 用户编号为空，生成编号中" << std::endl;
        user_info.user_number = util::generate_number(8);
    }
}

back_vo::user_info service::user::get_user(const get_vo::user_select &user_info) {
    return back_vo::user_info();
}
