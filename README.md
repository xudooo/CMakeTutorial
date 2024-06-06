根据[cmakeTutorialCN](https://github.com/shendeguize/CMakeTutorialCN)的各步骤生成此仓库

第4步，安装生成的产物使用命令
```shell
cd path_to_project
mkdir install
cd build
cmake ..
cmake --build .
cmake --install . --prefix="$(pwd)/../install"
```

第4步，测试用例
```shell
cd build
ctest
```