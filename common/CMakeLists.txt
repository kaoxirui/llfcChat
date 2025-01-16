# 定义库名称
add_library(log INTERFACE)

# 添加头文件路径
target_include_directories(log INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})