#include "base.hpp"

void problem_func() {}

//测试用例及其期望结果
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