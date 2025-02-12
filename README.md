# LeetCode 本地调试运行工程 (LocalLeetcode)

## 简介

本项目用于方便地在本地运行于测试leetcode的C++题目. 基于[local-leetcode项目](https://github.com/hzn-neu/local-leetcode)进行了简化与改造. 项目基于gtest进行测试

## 环境要求

- **编程语言**：C++
- **构建工具**：CMake
- **测试框架**：Google Test (gtest) (通过canon进行安装)
- **编译器**：支持 C++14 或更高版本的编译器（如 GCC, Clang, MSVC）

## 运行系统

可以直接运行于window系统中, 未来可能改造以运行于更多系统上

## 代码编译

将代码放入problems文件夹下, 在window系统下可以直接运行build.bat编译代码
代码会被编译入build文件夹下
运行clean_all.bat清理build文件

## 题目编写模板
为了更好的在本地刷题，可以按以下模板编写代码
```c++
#include "base.hpp"
#include "test.hpp"

// 左闭右开写法
int search(std::vector<int> &nums, int target) {
  int middle;
  int left = 0, right = nums.size();
  // 循环条件的判断就是看条件是否符合区间定义
  while (left < right) {
    middle = left + (right - left) / 2;
    if (nums[middle] > target) {
      right = middle;
    } else if (nums[middle] < target) {
      left = middle + 1;
    } else {
      return middle;
    }
  }
  return -1;
}


LEETCODE_TEST(search, -1, (std::vector<int>{}), 5)
LEETCODE_TEST(search, 0, (std::vector<int>{1}), 1)
LEETCODE_TEST(search, 0, (std::vector<int>{1, 2, 3, 4, 5}), 1)
LEETCODE_TEST(search, 2, (std::vector<int>{1, 2, 3, 4, 5}), 3)
```

## 贡献

欢迎任何形式的贡献！请按照以下步骤进行：

1. Fork 本仓库。
2. 创建新分支：git checkout -b feature/YourFeature
3. 提交更改：git commit -m '添加了某某功能'
4. 推送分支：git push origin feature/YourFeature
5. 创建 Pull Request。

欢迎star[本仓库](https://github.com/wyxx123/LocalLeetcode)及leetcode-local[原仓库](https://github.com/hzn-neu/local-leetcode)!