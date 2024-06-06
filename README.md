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

第7步，使用cpack构建二进制发行版
```shell
cd build
cpack
cpack -G ZIP -C Debug   # -G 指定生成器，-C 指定配置
cpack --config CPackSourceConfig.cmake  # 创建分发源
make package    # 创建分发源s
```

第8步，添加对dashboard的支持
[地址](https://my.cdash.org/index.php?project=CMakeTutorial&date=2024-06-05)

```shell
ctest [-VV] -D Experimental
```