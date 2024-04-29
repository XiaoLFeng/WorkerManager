//
// Created by 筱锋 on 24-4-19.
//

#include <iostream>
#include <chrono>
#include <cstdlib>

namespace util {
    /**
     * 生成一个随机数
     * 这个随机数是生成用于工号使用的随机数
     *
     * @param size
     * @return
     */
    static std::string generate_number(const int size) {
        srand((unsigned)time(nullptr));
        std::string number = "XF";
        for (int i = 0; i < size-2; i++)
            number =  number + std::to_string(rand()%10);
        return number;
    }


    /**
     * getCurrentTimestamp
     * 获取当前时间戳
     *
     * @return 返回当前时间戳
     */
    static unsigned long long getCurrentTimestamp() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()
                                                                             .time_since_epoch()).count();
    }
}
