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
  ListNode* deleteDuplicatesUnsorted(ListNode* head) {
    unordered_map<int, int> mp;
    ListNode* cur = head;
    while (cur) {
      ++mp[cur->val];
      cur = cur->next;
    }

    ListNode dummy(0);
    dummy.next = head;
    cur = head;
    ListNode* prev = &dummy;

    while (cur) {
      if (mp[cur->val] > 1) {
        prev->next = cur->next;
      } else {
        prev = cur;
      }

      cur = cur->next;
    }

    return dummy.next;
  }
};
// Runtime 1212 ms
// Memory 165.4 MB
// 2022.12.5 at 茗筑美嘉