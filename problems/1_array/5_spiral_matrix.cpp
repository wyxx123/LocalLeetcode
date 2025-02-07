#include "base.hpp"

// 循环不变量--->坚持左闭右开
std::vector<std::vector<int>> generateMatrix(int n) {
  std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

  int loop = n / 2; // 总共要循环几圈
  int start = 0, offset = 1;
  int num = 1;

  /*
      ------> j增大
  [ [a11 a12 a13 a14],  |
    [a21 a22 a23 a24],  |
    [a31 a32 a33 a34],  | i增大
    [a41 a42 a43 a44] ] V
  */
  while (loop--) {
    int i = start, j = start;
    // 左到右
    for (; j < n - offset; ++j) {
      matrix[i][j] = num++;
    }
    // 上到下
    for (; i < n - offset; ++i) {
      matrix[i][j] = num++;
    }
    // 右到左
    for (; j > start; --j) {
      matrix[i][j] = num++;
    }
    // 下到上
    for (; i > start; --i) {
      matrix[i][j] = num++;
    }
    start++;
    offset++;
  }

  // 如果数组边长是奇数，需要特殊处理中心点
  if (n % 2 == 1) {
    int mid = n / 2;
    matrix[mid][mid] = num;
  }
  return matrix;
}

struct TestCase {
  int n;
  std::vector<std::vector<int>> matrix;
};

class Tester : public testing::TestWithParam<TestCase> {};

TEST_P(Tester, FindsTargetIndex) {
  TestCase test = GetParam();
  std::vector<std::vector<int>> matrixult = generateMatrix(test.n);
  EXPECT_EQ(matrixult, test.matrix)
      << "Failed for input: " << test.n << " with matrix: " << test.matrix;
}

INSTANTIATE_TEST_SUITE_P(
    VariousInputs, Tester,
    testing::Values(
        TestCase{3, {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}}}, TestCase{1, {{1}}},
        TestCase{2, {{1, 2}, {4, 3}}},
        TestCase{4, {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}}}
        ));

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}