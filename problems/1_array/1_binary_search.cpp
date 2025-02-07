#include "base.hpp"

// 左闭右闭写法
//  int search(vector<int>& nums, int target) {
//    int middle;
//    int left = 0, right = nums.size() - 1;
// 循环条件的判断就是看条件是否符合区间定义
//   while (left <= right) {
//     middle = left + (right - left) / 2;
//     if (nums[middle] > target) {
//       right = middle - 1;
//     } else if (nums[middle] < target) {
//       left = middle + 1;
//     } else {
//       return middle;
//     }
//   }
//   return -1;
// }

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

struct TestCase {
  std::vector<int> nums;
  int target;
  int expected_index;
};

class Tester : public testing::TestWithParam<TestCase> {};

TEST_P(Tester, FindsTargetIndex) {
  // using ::operator<<;
  TestCase test = GetParam();
  std::vector<int> nums = test.nums;
  int result = search(nums, test.target);
  EXPECT_EQ(result, test.expected_index)
      << "Failed for input: " << nums << " with target: " << test.target;
}

INSTANTIATE_TEST_SUITE_P(
    VariousInputs, Tester,
    testing::Values(
        TestCase{{}, 5, -1}, TestCase{{1}, 1, 0}, TestCase{{1}, 2, -1},
        TestCase{{1, 2, 3, 4, 5}, 1, 0}, TestCase{{1, 2, 3, 4, 5}, 3, 2},
        TestCase{{1, 2, 3, 4, 5}, 5, 4}, TestCase{{1, 2, 3, 4, 5}, 0, -1},
        TestCase{{1, 3, 5, 7, 9}, 4, -1}, TestCase{{1, 2, 3, 4, 5}, 6, -1},
        // TestCase{ {1, 2, 2, 2, 3}, 2, 1 }, //
        // 二分查找对存在重复元素的数组不适用
        TestCase{{1, 2, 2, 2, 3}, 4, -1}, TestCase{{1, 2, 3, 4}, 3, 2},
        TestCase{{1, 2, 3, 4, 5}, 3, 2}));

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}