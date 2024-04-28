//
// Created by 筱锋 on 24-4-12.
//

#include "service.h"

/**
 * add_user 方法实现
 * 该方法用于添加用户信息
 * 返回值为是否添加成功
 *
 * @param user_info 用户信息
 * @return 是否添加成功
 */
bool service::user::add_user(const get_vo::user_create &user_info) {
    // 对用户的信息进行检查
    if (user_info.user_name.empty()) {
        std::cout << "[服务] 用户姓名为空" << std::endl;
        return false;
    }
    // 对用户的信息进行检查
    if (user_info.user_sex.empty()) {
        std::cout << "[服务] 用户性别为空" << std::endl;
        return false;
    }
    // 对用户的信息进行检查
    if (user_info.user_department.empty()) {
        std::cout << "[服务] 用户部门为空" << std::endl;
        return false;
    }
    // 对用户的信息进行检查
    if (user_info.user_wages.empty()) {
        std::cout << "[服务] 用户工资为空" << std::endl;
        return false;
    }
    // 对用户的信息进行检查
    if (user_info.user_level.empty()) {
        std::cout << "[服务] 用户级别为空" << std::endl;
        return false;
    }
    // 数据转换
    entity::UserDO userDO = entity::UserDO();
    if (user_info.user_number.empty()) {
        userDO.user_number = util::generate_number(8);
    } else {
        userDO.user_number = user_info.user_number;
    }
    userDO.user_name = user_info.user_name;
    userDO.user_sex = user_info.user_sex;
    userDO.user_department = user_info.user_department;
    userDO.user_wages = user_info.user_wages;
    userDO.user_level = user_info.user_level;
    userDO.user_position = user_info.user_position;

    // 数据插入
    try {
        sql::getXfUser
                .insert("id", "number", "name", "sex", "department", "wages", "level", "position", "created_at")
                .values(userDO.user_number, userDO.user_name, userDO.user_sex, userDO.user_department,
                        userDO.user_wages, userDO.user_level, userDO.user_position, util::getCurrentTimestamp())
                .execute();
        return true;
    } catch (const mysqlx::Error &err) {
        std::cout << "Error: " << err.what() << std::endl;
        return false;
    }
}

/**
 * get_user 方法实现
 * 该方法用于查询用户信息
 * 返回值为用户信息
 *
 * @param user_info 用户信息
 * @return 用户信息
 */
back_vo::user_info service::user::get_user(const get_vo::user_select &user_info) {
    return back_vo::user_info();
}

/**
 * edit_user 方法实现
 * 该方法用于修改用户信息
 * 返回值为是否修改成功
 *
 * @param user_info 用户信息
 * @return 是否修改成功
 */
bool service::user::edit_user(const get_vo::user_edit &user_info) {
    return false;
}

/**
 * delete_user 方法实现
 * 该方法用于删除用户信息
 * 返回值为是否删除成功
 *
 * @param user_info 用户信息
 * @return 是否删除成功
 */
bool service::user::delete_user(const std::string number) {
    return false;
}

/**
 * get_user_by_username 方法实现
 * 该方法用于查询用户信息
 * 返回值为用户信息
 *
 * @param user_info 用户信息
 * @return 用户信息
 */
back_vo::user_info *service::user::get_user_by_username(const std::string username) {
    back_vo::user_info *user_info = new back_vo::user_info();
    mysqlx::RowResult result = sql::getXfUser
            .select("name")
            .where("name = " + username)
            .bind("name", user_info->user_name)
            .bind("sex", user_info->user_sex)
            .bind("department", user_info->user_department)
            .bind("wages", user_info->user_wages)
            .bind("level", user_info->user_level)
            .execute();
    return user_info;
}
