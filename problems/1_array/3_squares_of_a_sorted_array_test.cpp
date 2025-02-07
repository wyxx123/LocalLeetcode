#include "base.hpp"

// 暴力解法
// vector<int> sortedSquares(vector<int> &nums) {
//   for (int &num : nums) {
//     num = num * num;
//   }
//   sort(nums.begin(), nums.end());
//   return nums;
// }

// 双指针解法
std::vector<int> sortedSquares(std::vector<int> &nums) {
  int left = 0, right = nums.size() - 1;
  std::vector<int> ans(nums.size());
  int pos = nums.size() - 1;

  while (left <= right) {
    if (abs(nums[left]) >= abs(nums[right])) {
      ans[pos--] = nums[left] * nums[left];
      left++;
    } else {
      ans[pos--] = nums[right] * nums[right];
      right--;
    }
  }

  return ans;
}

struct TestCase {
  std::vector<int> input;
  std::vector<int> expected;
};

class Tester : public testing::TestWithParam<TestCase> {};

TEST_P(Tester, HandlesVariousCases) {
  TestCase test = GetParam();
  std::vector<int> input = test.input;
  std::vector<int> result = sortedSquares(input);
  EXPECT_EQ(result, test.expected) << "Failed for input: " << test.input;
}

INSTANTIATE_TEST_SUITE_P(
    VariousInputs, Tester,
    testing::Values(TestCase{{-4, -1, 0, 3, 10}, {0, 1, 9, 16, 100}},
                    TestCase{{-7, -3, 2, 3, 11}, {4, 9, 9, 49, 121}},
                    TestCase{{1, 2, 3, 4}, {1, 4, 9, 16}},
                    TestCase{{-3, -2, -1}, {1, 4, 9}}, TestCase{{}, {}},
                    TestCase{{0}, {0}}, TestCase{{-1, 0, 1}, {0, 1, 1}},
                    TestCase{{-2, -2, 0, 2, 2}, {0, 4, 4, 4, 4}},
                    TestCase{{-5, -3, -2, -1}, {1, 4, 9, 25}},
                    TestCase{{0, 0, 0}, {0, 0, 0}}));

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}