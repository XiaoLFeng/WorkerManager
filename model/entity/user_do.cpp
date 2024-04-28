//
// Created by 筱锋 on 24-4-28.
//

#include <iostream>

namespace entity {
    /**
    * UserDO 类
    * 该类用于存储用户信息
    */
    class UserDO {
    public:
        std::string user_number;
        std::string user_name;
        std::string user_sex;
        std::string user_department;
        std::string user_wages;
        std::string user_level;
        std::string user_position;
    };
}