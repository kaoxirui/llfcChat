cmake_minimum_required(VERSION 3.10)
project(test)
find_package(jsoncpp REQUIRED)

add_executable(testjson ./src/testjson.cpp)

target_link_libraries(testjson jsoncpp_lib)

add_executable(testredis ./src/testredis.cpp)

target_link_libraries(testredis hiredis)