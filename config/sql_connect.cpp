//
// Created by 筱锋 on 24-4-12.
//
#include <iostream>
#include <mysqlx/xdevapi.h>

using namespace mysqlx;
using namespace std;

// 定义一个全局变量，用来保存连接句
namespace sql {
    static std::string sqlUrl = "mysqlx://root@127.0.0.1";
    static Session sqlSession(sqlUrl);
}