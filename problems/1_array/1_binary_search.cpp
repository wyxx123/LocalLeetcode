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

