## 使用方法

1. 解题
   1. 在 include 中新增对应的 `.hpp` 代码
   2. 实现 `run()` 方法构造用例并调用 leetcode 中的函数
2. 修改 `solution.cpp`
   1. `#include` 题解中的 `.hpp` 代码
3. 编译运行
    ``` bash
    cmake -S . -B build
    cmake --build build
    ./build/solution
    ```
