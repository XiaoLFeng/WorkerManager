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
bool service::user::add_user(get_vo::user_create *user_info) {
    // 对用户的信息进行检查
    if (user_info->user_name.empty()) {
        std::cout << "[服务] 用户姓名为空" << std::endl;
        return false;
    }
    // 对用户的信息进行检查
    int sex;
    if (user_info->user_sex.empty()) {
        std::cout << "[服务] 用户性别为空" << std::endl;
        return false;
    } else {
        if (user_info->user_sex == "男") {
            sex = 0;
        } else {
            sex = 1;
        }
    }
    // 对用户的信息进行检查
    if (user_info->user_department.empty()) {
        std::cout << "[服务] 用户部门为空" << std::endl;
        return false;
    }
    // 对用户的信息进行检查
    if (user_info->user_wages.empty()) {
        std::cout << "[服务] 用户工资为空" << std::endl;
        return false;
    }
    // 对用户的信息进行检查
    if (user_info->user_level.empty()) {
        std::cout << "[服务] 用户级别为空" << std::endl;
        return false;
    }
    // 数据转换

    try {
        mysqlx::Session sqlSession("localhost", 33060, "root", "");
        std::string sql =
                "INSERT INTO work_manager.xf_user (number, name, sex, department, money, level, posts) VALUES ('"
                + util::generate_number(10) + "', '"
                + user_info->user_name + "', "
                + to_string(sex) + ", '"
                + user_info->user_department + "', '"
                + user_info->user_wages + "', '"
                + user_info->user_level + "', '"
                + user_info->user_position + "')";
        sqlSession
                .sql(sql)
                .execute();
        return true;
    } catch (const mysqlx::Error &e) {
        cerr << "Error: " << e.what() << endl;
    } catch (std::exception &e) {
        cerr << "Error: " << e.what() << endl;
    } catch (...) {
        cerr << "Unknown error!" << endl;
    }
    return false;
}

/**
 * get_user 方法实现
 * 该方法用于查询用户信息
 * 返回值为用户信息
 *
 * @param user_info 用户信息
 * @return 用户信息
 */
void service::user::get_user(const get_vo::user_select &user_info) {
    mysqlx::Session sqlSession("localhost", 33060, "root", "");
    mysqlx::RowResult getData = sqlSession.sql(
                    "SELECT * FROM work_manager.xf_user WHERE name = '" + user_info.user + "' LIMIT 1")
            .execute();
    while (auto row = getData.fetchOne()) {
        // 展示用户的信息
        cout << "员工信息如下：" << endl;
        cout << "员工编号：" << row[1] << endl;
        cout << "员工姓名：" << row[2] << endl;
        cout << "员工性别：" << row[3] << endl;
        cout << "员工部门：" << row[4] << endl;
        cout << "员工工资：" << row[5] << endl;
        cout << "员工级别：" << row[6] << endl;
        cout << "员工职位：" << row[7] << endl;
    }
}

/**
 * edit_user 方法实现
 * 该方法用于修改用户信息
 * 返回值为是否修改成功
 *
 * @param user_info 用户信息
 * @return 是否修改成功
 */
bool service::user::edit_user(const get_vo::user_edit *user_info) {
    // 对用户的信息进行检查
    if (user_info->user_name.empty()) {
        std::cout << "[服务] 用户姓名为空" << std::endl;
        return false;
    }
    // 对用户的信息进行检查
    int sex;
    if (user_info->user_sex.empty()) {
        std::cout << "[服务] 用户性别为空" << std::endl;
        return false;
    } else {
        if (user_info->user_sex == "男") {
            sex = 0;
        } else {
            sex = 1;
        }
    }
    // 对用户的信息进行检查
    if (user_info->user_department.empty()) {
        std::cout << "[服务] 用户部门为空" << std::endl;
        return false;
    }
    // 对用户的信息进行检查
    if (user_info->user_wages.empty()) {
        std::cout << "[服务] 用户工资为空" << std::endl;
        return false;
    }
    // 对用户的信息进行检查
    if (user_info->user_level.empty()) {
        std::cout << "[服务] 用户级别为空" << std::endl;
        return false;
    }
    // 数据转换

    try {
        mysqlx::Session sqlSession("localhost", 33060, "root", "");
        std::string sql =
                "UPDATE work_manager.xf_user SET"
                " name='" + user_info->user_name + "',"
                " sex='" + to_string(sex) + "',"
                " department='" + user_info->user_department + "',"
                " money='" + user_info->user_wages + "',"
                " level='" + user_info->user_level + "',"
                " posts='" + user_info->user_position + "' WHERE number='" + user_info->user_number + "'";
        sqlSession
                .sql(sql)
                .execute();
        return true;
    } catch (const mysqlx::Error &e) {
        cerr << "Error: " << e.what() << endl;
    } catch (std::exception &e) {
        cerr << "Error: " << e.what() << endl;
    } catch (...) {
        cerr << "Unknown error!" << endl;
    }
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
    try {
        mysqlx::Session sqlSession("localhost", 33060, "root", "");
        std::string sql =
                "DELETE FROM work_manager.xf_user WHERE number = '"+ number +"'";
        sqlSession
                .sql(sql)
                .execute();
        return true;
    } catch (const mysqlx::Error &e) {
        cerr << "Error: " << e.what() << endl;
    } catch (std::exception &e) {
        cerr << "Error: " << e.what() << endl;
    } catch (...) {
        cerr << "Unknown error!" << endl;
    }
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
std::string service::user::get_user_by_username(const std::string &username) {
    mysqlx::Session sqlSession("localhost", 33060, "root", "");
    mysqlx::RowResult getData = sqlSession.sql(
                    "SELECT number FROM work_manager.xf_user WHERE name = '" + username + "' LIMIT 1")
            .execute();
    cout << "有操作" << endl;
    while (auto row = getData.fetchOne()) {
        cout << "有数据：" << row[0] << endl;
        mysqlx::Value getNumber = row[0];
        std::string *strValue;
        if (getNumber.getType() == mysqlx::Value::Type::STRING) {
            return getNumber.get<std::string>();
        } else {
            return "";
        }
    }
    return "";
}
