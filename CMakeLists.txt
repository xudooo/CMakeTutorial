cmake_minimum_required(VERSION 3.10)

# 设置项目名和版本号
project(Test VERSION 1.0)

# 指定C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 控制静态库和共享库的构建位置，无需修改运行可执行文件的位置
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_SHARED_LIBS "BuildUse my math implementation" ON)

# 配置头文件，仅传递版本号给源代码
configure_file(config.h.in config.h)

# 添加MathFunctions库
add_subdirectory(MathFunctions)

# 添加可执行文件
add_executable(Test test.cpp)

# 链接MathFunctions库
target_link_libraries(Test PUBLIC MathFunctions)

# 将二叉树添加到包含文件的搜索路径
# 这样我们就可以找到 config.h
target_include_directories(Test PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

# 添加安装目标
install(TARGETS Test DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/config.h"
        DESTINATION include
        )

# 启用测试
include(CTest)

# 应用程序是否运行
add_test(NAME Runs COMMAND Test 25)

# 使用消息是否有效
add_test(NAME Usage COMMAND Test)
set_tests_properties(Usage
        PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
        )

# 定义一个程序以简化添加测试
function(do_test target arg result)
    add_test(NAME Comp${arg} COMMAND ${target} ${arg})
    set_tests_properties(Comp${arg}
        PROPERTIES PASS_REGULAR_EXPRESSION ${result}
        )
endfunction(do_test)

# 做一些基于结果的测试
do_test(Test 4          "is 2")
do_test(Test 9          "is 3")
do_test(Test 5          "is 2.236")
do_test(Test 0.0        "is 0")
do_test(Test -0.0       "is 0")
do_test(Test -25        "is [-nan|nan|0]")
do_test(Test 0.0001     "is 0.01")

# 安装程序
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Test_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Test_VERSION_MINOR}")
include(CPack)
