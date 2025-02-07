#include "base.hpp"

// 暴力解法
// int minSubArrayLen(int target, std::vector<int> &nums) {
//   int minlen = INT32_MAX;
//   for (size_t i = 0; i < nums.size(); ++i) {
//     int sum = 0;
//     for (size_t j = i; j < nums.size(); ++j) {
//       sum += nums[j];
//       if (sum >= target) {
//         minlen = minlen < j - i + 1 ? minlen : j - i + 1; //注意这里的len需要 +1
//         break;
//       }
//     }
//   }
//   return minlen == INT32_MAX ? 0 : minlen;
// }

// 滑动窗口--->双指针
int minSubArrayLen(int target, std::vector<int> &nums) {
  int start = 0, end = 0;
  int sum = 0;
  int min_len = INT32_MAX;

  while (end < nums.size()) {
    sum += nums[end];       //好久不做这个题，在这end++，发现死活不对o(╥﹏╥)o
    while (sum >= target) {
      min_len = min_len < end - start + 1 ? min_len : end - start + 1;
      sum -= nums[start];
      start++;
    }
    end++;
  }

  return min_len == INT32_MAX ? 0 : min_len;
}

struct TestCase {
  std::vector<int> nums;
  int target;
  int expected_min_length;
};

class Tester : public testing::TestWithParam<TestCase> {};

TEST_P(Tester, FindsTargetIndex) {
  TestCase test = GetParam();
  std::vector<int> nums = test.nums;
  int result = minSubArrayLen(test.target, test.nums);
  EXPECT_EQ(result, test.expected_min_length)
      << "Failed for input: " << nums << " with target: " << test.target;
}

INSTANTIATE_TEST_SUITE_P(VariousInputs, Tester,
                         testing::Values(TestCase{{2, 3, 1, 2, 4, 3}, 7, 2},
                                         TestCase{{1, 4, 4}, 4, 1},
                                         TestCase{
                                             {1, 1, 1, 1, 1, 1, 1, 1}, 11, 0},
                                         TestCase{{2,3,1,2,4,3}, 7, 2}));

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}