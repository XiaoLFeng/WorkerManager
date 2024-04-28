//
// Created by 筱锋 on 24-4-19.
//

#include <iostream>

namespace util {
    // generate_number
    // 该方法用于生成一个指定长度的随机数
    static std::string generate_number(const int size) {
        std::string number = "XF";
        for (int i = 0; i < size; i++) {
            number += std::to_string(rand_r(reinterpret_cast<unsigned int *>(10)));
        }
        return number;
    }
}
