cmake_minimum_required(VERSION 3.28)
project(WorkerManager)

set(CMAKE_CXX_STANDARD 17)
set(MYSQL_INCLUDE "/opt/homebrew/Cellar/mysql-connector-c++/8.3.0/include")
set(MYSQL_LIB "/opt/homebrew/Cellar/mysql-connector-c++/8.3.0/lib")
set(OPENSSL_ROOT_DIR "/opt/homebrew/opt/openssl@3")

include_directories(${MYSQL_INCLUDE})
include_directories(${OPENSSL_ROOT_DIR}/include)

link_directories(${MYSQL_LIB})
link_directories(${OPENSSL_ROOT_DIR}/lib)

add_executable(WorkerManager main.cpp
        services/user.cpp
        services/service.h
        config/sql_connect.cpp
        model/vo/get/user_create.cpp
        data_processing.h
        model/vo/get/user_select.cpp
        model/vo/back/user_info.cpp
        processing_util.cpp
        model/entity/user_do.cpp
)

find_library(MYSQLCPPCONN_LIB NAMES mysqlcppconn PATHS ${MYSQL_LIB})
message(STATUS "Found MySQLCPPCONN: ${MYSQLCPPCONN_LIB}")

find_library(SSL_LIB NAMES ssl PATHS ${OPENSSL_ROOT_DIR}/lib)
find_library(CRYPTO_LIB NAMES crypto PATHS ${OPENSSL_ROOT_DIR}/lib)
message(STATUS "Found SSL: ${SSL_LIB}")
message(STATUS "Found Crypto: ${CRYPTO_LIB}")

target_link_libraries(WorkerManager ${MYSQLCPPCONN_LIB} ${SSL_LIB} ${CRYPTO_LIB})
