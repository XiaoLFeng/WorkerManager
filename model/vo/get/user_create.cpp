//
// Created by 筱锋 on 24-4-12.
//
#include <iostream>

namespace get_vo {
    class user_create {
    public:
        // 用户姓名
        std::string user_name;
        // 用户性别
        std::string user_sex;
        // 用户部门
        std::string user_department;
        // 用户工资
        std::string user_wages;
        // 用户级别
        std::string user_level;
        // 用户职位
        std::string user_position;
    };

    class user_edit {
    public:
        // 用户号
        std::string user_number;
        // 用户姓名
        std::string user_name;
        // 用户性别
        std::string user_sex;
        // 用户部门
        std::string user_department;
        // 用户工资
        std::string user_wages;
        // 用户级别
        std::string user_level;
        // 用户职位
        std::string user_position;
    };
}