根据cmakeTutorialCN的各步骤生成此仓库

第4步，安装生成的产物使用命令
```shell
cd path_to_project
mkdir install
cd build
cmake ..
cmake --build .
cmake --install . --prefix="$(pwd)/../install"
```