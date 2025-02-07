#include "base.hpp"

ListNode *removeElements(ListNode *head, int val) {
  ListNode *dummy = new ListNode(0, head);
}

struct TestCase {
  std::vector<int> input;
  int val;
  std::vector<int> expected;
};

std::ostream &operator<<(std::ostream &os, const struct TestCase &test) {
  os << "{ nums: " << listToVector(vectorToList(test.input))
     << ", val: " << test.val << ", expected: " << test.expected << " }";
  return os;
}

class Tester : public ::testing::TestWithParam<TestCase> {};

TEST_P(Tester, RemovesSpecifiedElements) {
  TestCase test = GetParam();
  ListNode *head = vectorToList(test.input);
  ListNode *result = removeElements(head, test.val);
  std::vector<int> result_vec = listToVector(result);
  EXPECT_EQ(result_vec, test.expected)
      << "Failed for input: " << test.input << " with val: " << test.val;

  while (result != nullptr) {
    ListNode *temp = result;
    result = result->next;
    delete temp;
  }
}

INSTANTIATE_TEST_SUITE_P(
    VariousInputs, Tester,
    testing::Values(TestCase{{}, 3, {}}, TestCase{{3, 3, 3}, 3, {}},
                    TestCase{{1, 2, 4, 5}, 3, {1, 2, 4, 5}},
                    TestCase{{3, 3, 1, 2, 4}, 3, {1, 2, 4}},
                    TestCase{{1, 3, 3, 3, 4, 5}, 3, {1, 4, 5}},
                    TestCase{{1, 2, 3, 3, 3}, 3, {1, 2}}, TestCase{{3}, 3, {}},
                    TestCase{{2}, 3, {2}},
                    TestCase{{1, 2, 2, 3, 3, 4}, 2, {1, 3, 3, 4}},
                    TestCase{{2, 2, 2, 2}, 2, {}},
                    TestCase{{1, 2, 2, 4, 5, 5}, 3, {1, 2, 2, 4, 5, 5}},
                    TestCase{{-1, -1, 0, 1, 2}, -1, {0, 1, 2}},
                    TestCase{{0, 1, 2, 0, 3, 0, 4}, 0, {1, 2, 3, 4}},
                    TestCase{{-3, -2, -2, 0, 1, 2, -2}, -2, {-3, 0, 1, 2}},
                    TestCase{{}, 0, {}},
                    TestCase{{1, 2, 3, 4, 5}, 6, {1, 2, 3, 4, 5}}));

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}