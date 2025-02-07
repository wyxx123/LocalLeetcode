#include <gtest/gtest.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *vectorToList(const std::vector<int> &vec) {
  ListNode dummy(0);
  ListNode *current = &dummy;
  for (int num : vec) {
    current->next = new ListNode(num);
    current = current->next;
  }
  return dummy.next;
}

std::vector<int> listToVector(ListNode *head) {
  std::vector<int> vec;
  while (head != nullptr) {
    vec.push_back(head->val);
    head = head->next;
  }
  return vec;
}

namespace std{
ostream &operator<<(ostream &os, const vector<int> &vec) {
  os << "[";
  for (size_t i = 0; i < vec.size(); ++i) {
    if (i > 0) {
      os << ", ";
    }
    os << vec[i];
  }
  os << "]";
  return os;
}

std::ostream &operator<<(std::ostream &os,
                         const std::vector<std::vector<int>> &vec) {
  os << "[\n";
  for (const auto &row : vec) {
    os << "  [ ";
    for (const auto &elem : row) {
      os << elem << " ";
    }
    os << "]\n";
  }
  os << "]";
  return os;
}

std::ostream &operator<<(std::ostream &os, const ListNode *list) {
  const ListNode *current = list;
  while (current != nullptr) {
    os << current->val;
    if (current->next != nullptr) {
      os << " -> ";
    }
    current = current->next;
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, ListNode *head) {
  std::vector<int> vec = listToVector(head);
  os << "[";
  for (size_t i = 0; i < vec.size(); ++i) {
    if (i > 0) os << ", ";
    os << vec[i];
  }
  os << "]";
  return os;
}
}