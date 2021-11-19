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
  ListNode* reverseEvenLengthGroups(ListNode* head) {
    ListNode* cur = head;
    ListNode* prev = head;

    int g = 1;

    while (cur) {
      ListNode* next = cur;

      int cnt = 0;

      while (next) {
        ++cnt;

        if (cnt == g) {
          break;
        }

        next = next->next;
      }

      ++g;

      if (cnt & 1) {
        while (cnt-- > 0) {
          prev = cur;
          cur = cur->next;
        }
        continue;
      }

      --cnt;
      while (cnt-- > 0) {
        next = cur->next;
        cur->next = cur->next->next;
        next->next = prev->next;
        prev->next = next;
      }

      prev = cur;
      cur = cur->next;
    }

    return head;
  }
};
// Runtime: 980 ms, faster than 78.87%
// Memory Usage: 329.7 MB, less than 70.90%
// 2021.11.19 at  奥盛大厦