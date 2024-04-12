//
// Created by 筱锋 on 24-4-12.
//

#include "service.h"

bool service::user::add_user(const back_vo::user_info &user_info) {
    // 对数据进行查询
}

back_vo::user_info service::user::get_user(const get_vo::user_select &user) {
    // 获取信息对数据库进行查询
    return back_vo::user_info();
}
