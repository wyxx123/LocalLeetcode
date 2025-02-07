#include <gtest/gtest.h>

#include <experimental/tuple>
#include <tuple>
#include <utility>

//* 添加辅助宏用于正确拼接行号
#define CONCAT_IMPL(a, b) a##b
#define CONCAT(a, b) CONCAT_IMPL(a, b)

/*
 * 宏 LEETCODE_TEST_EX 的参数说明：
 *   func     : 待测试函数名
 *   expected : 预期输出（可以是基本类型、对象等）
 *   cmp      : 比较函数（应是一个返回 bool 的表达式，比如 lambda），接受
 * (result, expected)
 *   __VA_ARGS__ : 不定数量的输入参数，将传递给 func
 *
 * 使用方式：
 *   LEETCODE_TEST_EX(addAndMultiply, 12, [](int res, int exp) { return res ==
 * exp; }, 2, 2, 3);
 *
 * 上述调用相当于调用 addAndMultiply(2,2,3) 得到结果 12，
 * 然后使用 lambda 判断结果与预期是否相等。
 */
#define LEETCODE_TEST_EX(func, expected, cmp, ...)                      \
  TEST(func##_Test, CONCAT(Test_, __LINE__)) {                          \
    auto tup = std::make_tuple(__VA_ARGS__);                            \
    auto result = std::experimental::apply(func, tup);                  \
    ASSERT_TRUE(cmp(result, expected))                                  \
        << "Test failed: expected " << testing::PrintToString(expected) \
        << ", but got " << testing::PrintToString(result);              \
  }

/*
 * 如果不需要自定义比较逻辑，也可以提供一个简化版的宏，默认使用 EXPECT_EQ：
 *
 *   LEETCODE_TEST(func, expected, __VA_ARGS__)
 *
 * 示例：
 *   LEETCODE_TEST(addAndMultiply, 12, 2, 2, 3);
 */
#define LEETCODE_TEST(func, expected, ...)                              \
  TEST(func##_Test, CONCAT(Test_, __LINE__)) {                          \
    auto tup = std::make_tuple(__VA_ARGS__);                            \
    auto result = std::experimental::apply(func, tup);                  \
    EXPECT_EQ(result, expected)                                         \
        << "Test failed: expected " << testing::PrintToString(expected) \
        << ", but got " << testing::PrintToString(result);              \
  }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}