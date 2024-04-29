cmake_minimum_required(VERSION 3.28)
project(WorkerManager)

set(CMAKE_CXX_STANDARD 17)
set(MYSQL_INCLUDE "/usr/local/mysql-connector-c++-8.3.0/include")
set(MYSQL_LIB "/usr/local/mysql-connector-c++-8.3.0/lib64")

#添加头文件搜索路径
include_directories(${MYSQL_INCLUDE})
#添加库文件搜索路径
link_directories(${MYSQL_LIB})

add_executable(WorkerManager main.cpp
        services/user.cpp
        services/service.h
        model/vo/get/user_create.cpp
        data_processing.h
        model/vo/get/user_select.cpp
        model/vo/back/user_info.cpp
        processing_util.cpp
        model/entity/user_do.cpp
)

# Link the MySQL Connector/C++ library
target_link_libraries(WorkerManager mysqlcppconn8)