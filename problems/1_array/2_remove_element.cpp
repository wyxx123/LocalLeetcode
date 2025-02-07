#include "base.hpp"

// 暴力解法
//  int removeElement(vector<int> &nums, int val) {
//    size_t size = nums.size();
//    for (size_t i = 0; i < size; ) {
//      if (nums[i] == val) {
//        for (size_t j = i; j < size - 1; ++j) {
//          nums[j] = nums[j + 1];
//        }
//        size--;
//      } else {
//        ++i;
//      }
//    }
//    return size;
//  }

// 使用标准库的暴力解法
// int removeElement(vector<int> &nums, int val) {
//   int size = nums.size();
//   for (auto iter = nums.begin(); iter != nums.end();) {
//     if (*iter == val) {
/*
  遍历nums时，如果调用 erase(iter)，会导致当前 iter 失效
  删除元素后iter会返回删除后下一个元素的迭代器
*/
//       iter = nums.erase(iter);
//       size--;
//     } else {
//       iter++;
//     }
//   }
//   return size;
// }

// 快慢指针
int removeElement(std::vector<int> &nums, int val) {
  size_t fast = 0, slow = 0;
  for (; fast < nums.size(); ++fast) {
    if (nums[fast] != val) {
      nums[slow++] = nums[fast];
    }
  }
  return slow;
}

struct TestCase {
  std::vector<int> nums;
  int val;
  std::vector<int> expected_nums;
  int expected_size;
};

class Tester : public testing::TestWithParam<TestCase> {};

TEST_P(Tester, RemovesSpecifiedElements) {
  TestCase test = GetParam();
  std::vector<int> nums = test.nums;
  int new_size = removeElement(nums, test.val);
  EXPECT_EQ(new_size, test.expected_size)
      << "Failed for input: " << test.nums << " with val: " << test.val;

  std::vector<int> result(nums.begin(), nums.begin() + new_size);
  EXPECT_EQ(result, test.expected_nums)
      << "Mismatch in modified array for input: " << test.nums
      << " with val: " << test.val;
}

INSTANTIATE_TEST_SUITE_P(
    VariousInputs, Tester,
    testing::Values(TestCase{{}, 3, {}, 0}, TestCase{{3, 3, 3}, 3, {}, 0},
                    TestCase{{1, 2, 4, 5}, 3, {1, 2, 4, 5}, 4},
                    TestCase{{3, 3, 1, 2, 4}, 3, {1, 2, 4}, 3},
                    TestCase{{1, 3, 3, 3, 4, 5}, 3, {1, 4, 5}, 3},
                    TestCase{{1, 2, 3, 3, 3}, 3, {1, 2}, 2},
                    TestCase{{3}, 3, {}, 0}, TestCase{{2}, 3, {2}, 1},
                    TestCase{{1, 2, 2, 3, 3, 4}, 2, {1, 3, 3, 4}, 4},
                    TestCase{{2, 2, 2, 2}, 2, {}, 0},
                    TestCase{{1, 2, 2, 4, 5, 5}, 3, {1, 2, 2, 4, 5, 5}, 6},
                    TestCase{{-1, -1, 0, 1, 2}, -1, {0, 1, 2}, 3},
                    TestCase{{0, 1, 2, 0, 3, 0, 4}, 0, {1, 2, 3, 4}, 4}));

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}