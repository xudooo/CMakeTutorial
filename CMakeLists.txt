cmake_minimum_required(VERSION 3.10)

# 设置项目名和版本号
project(Test VERSION 1.0)

# 指定C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 配置头文件以将某些 CMake 设置传递给源代码
configure_file(config.h.in config.h)

# 添加MathFunctions库
add_subdirectory(MathFunctions)

# 添加可执行文件
add_executable(Test test.cpp)

target_link_libraries(Test PUBLIC MathFunctions)

# 将二叉树添加到包含文件的搜索路径
# 这样我们就可以找到 config.h
target_include_directories(Test PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_BINARY_DIR}/MathFunctions"
                           )