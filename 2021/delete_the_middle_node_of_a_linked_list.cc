/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* deleteMiddle(ListNode* head) {
    int cnt = 0;

    ListNode* cur = head;

    while (cur) {
      ++cnt;

      cur = cur->next;
    }

    cnt /= 2;

    ListNode* prev = nullptr;
    cur = head;

    while (cnt-- > 0) {
      prev = cur;
      cur = cur->next;
    }

    if (prev) {
      prev->next = cur->next;
    } else {
      head = prev;
    }

    return head;
  }
};
// Runtime: 844 ms, faster than 7.14%
// Memory Usage: 294.7 MB, less than 14.29%
// 2021.12.6 at 奥盛大厦

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* deleteMiddle(ListNode* head) {
    if (!head->next) {
      return nullptr;
    }

    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = nullptr;

    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    prev->next = slow->next;

    return head;
  }
};
// Runtime: 896 ms, faster than 7.14%
// Memory Usage: 294.9 MB, less than 14.29%
// 2021.12.6 at 奥盛大厦