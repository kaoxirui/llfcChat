cmake_minimum_required(VERSION 3.14)

project(CChat)


set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

#定义DEBUG宏，在编译时才能启用LOG_DEBUG输出
add_definitions(-DDEBUG)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_FILE_OFFSET_BITS=64 -std=c++20")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2 -DNDEBUG")

# include_directories(${PROJECT_SOURCE_DIR}/thirdParty/spdlog-1.14.0/include)
include_directories(/usr/local/include)

set(Boost_INCLUDE_DIR "/usr/include")
set(Boost_LIBRARY_DIR "/usr/lib/x86_64-linux-gnu")
find_package(Boost REQUIRED COMPONENTS system filesystem)
find_package(jsoncpp REQUIRED)
find_package(Protobuf REQUIRED)
find_package(gRPC CONFIG REQUIRED)

# find_package(hiredis REQUIRED) # 查找 hiredis
# find_package(MySQLConnector REQUIRED) # 查找 MySQL Connector/C++
set(COMMON_LIBS
  Boost::system
  Boost::filesystem
  pthread
  gRPC::grpc++
  jsoncpp
  hiredis
  mysqlcppconn
)

 add_subdirectory(ChatServer)
# add_subdirectory(ChatServer2)
add_subdirectory(GateServer)
add_subdirectory(common)
add_subdirectory(StatusServer)