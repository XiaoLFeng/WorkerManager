//
// Created by 筱锋 on 24-4-12.
//
#include <mysqlx/xdevapi.h>

using namespace mysqlx;
using namespace std;

// 定义一个全局变量，用来保存连接句
namespace sql {
    // 创建一个连接
    static Session sqlSession("localhost", 3306, "worker_manager", "123456123456", "worker_manager");

    // 定义一个全局变量，用来保存数据库中的表
    static Table getXfUser = sqlSession.getSchema("worker_manager").getTable("xf_user");
}