#include "base.hpp"
#include "test.hpp"
#include <vector>

// 错误示例
ListNode *removeElements(ListNode *head, int val) {
  ListNode *dummy = new ListNode(0, head);
  return dummy;
}

bool cmp(ListNode* result, std::vector<int> expected) {
  int res_size = 0;
  while (result != nullptr) {
    if (res_size < expected.size() && result->val != expected[res_size])
      return false;
    ++res_size;
    ListNode* tmp = result;
    result = result->next;
    delete tmp;
  }
  if (res_size != expected.size()) return false;
  return true;
}

LEETCODE_TEST_EX(removeElements, (std::vector<int>{}), cmp, vectorToList(std::vector<int>{}), 3)
LEETCODE_TEST_EX(removeElements, (std::vector<int>{}), cmp, vectorToList(std::vector<int>{}), 3)

// INSTANTIATE_TEST_SUITE_P(
//     VariousInputs, Tester,
//     testing::Values(TestCase{{}, 3, {}}, TestCase{{3, 3, 3}, 3, {}},
//                     TestCase{{1, 2, 4, 5}, 3, {1, 2, 4, 5}},
//                     TestCase{{3, 3, 1, 2, 4}, 3, {1, 2, 4}},
//                     TestCase{{1, 3, 3, 3, 4, 5}, 3, {1, 4, 5}},
//                     TestCase{{1, 2, 3, 3, 3}, 3, {1, 2}}, TestCase{{3}, 3, {}},
//                     TestCase{{2}, 3, {2}},
//                     TestCase{{1, 2, 2, 3, 3, 4}, 2, {1, 3, 3, 4}},
//                     TestCase{{2, 2, 2, 2}, 2, {}},
//                     TestCase{{1, 2, 2, 4, 5, 5}, 3, {1, 2, 2, 4, 5, 5}},
//                     TestCase{{-1, -1, 0, 1, 2}, -1, {0, 1, 2}},
//                     TestCase{{0, 1, 2, 0, 3, 0, 4}, 0, {1, 2, 3, 4}},
//                     TestCase{{-3, -2, -2, 0, 1, 2, -2}, -2, {-3, 0, 1, 2}},
//                     TestCase{{}, 0, {}},
//                     TestCase{{1, 2, 3, 4, 5}, 6, {1, 2, 3, 4, 5}}));

