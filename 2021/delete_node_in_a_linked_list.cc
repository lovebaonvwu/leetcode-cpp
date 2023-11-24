/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  void deleteNode(ListNode* node) { *node = *node->next; }
};
// Runtime: 8 ms, faster than 98.92%
// Memory Usage: 9.1 MB, less than 100.00%