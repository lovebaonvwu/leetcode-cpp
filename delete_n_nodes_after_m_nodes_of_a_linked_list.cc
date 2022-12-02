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
  ListNode* deleteNodes(ListNode* head, int m, int n) {
    ListNode* cur = head;
    while (cur) {
      int M = m;
      ListNode* prev;
      while (cur && M-- > 0) {
        prev = cur;
        cur = cur->next;
      }

      int N = n;
      while (cur && N-- > 0) {
        cur = cur->next;
      }

      prev->next = cur;
    }

    return head;
  }
};
// Runtime 39 ms
// Memory 15.7 MB
// 2022.12.2 at 茗筑美嘉