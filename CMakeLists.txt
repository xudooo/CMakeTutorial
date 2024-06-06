cmake_minimum_required(VERSION 3.10)

# 设置项目名和版本号
project(Test VERSION 1.0)

# 指定C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加配置项，是否需要自己的数学库
option(USE_MYMATH "Use my math implementation" ON)

# 配置头文件以将某些 CMake 设置传递给源代码
configure_file(config.h.in config.h)

# 添加MathFunctions库
if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

# 添加可执行文件
add_executable(Test test.cpp)

target_link_libraries(Test PUBLIC ${EXTRA_LIBS})

# 将二叉树添加到包含文件的搜索路径
# 这样我们就可以找到 config.h
target_include_directories(Test PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${EXTRA_INCLUDES}
                           )