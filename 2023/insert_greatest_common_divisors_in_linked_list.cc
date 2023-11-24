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
  ListNode* insertGreatestCommonDivisors(ListNode* head) {
    ListNode* cur = head;
    while (cur && cur->next) {
      ListNode* inserted = new ListNode(__gcd(cur->val, cur->next->val));
      ListNode* next = cur->next;
      cur->next = inserted;
      inserted->next = next;
      cur = next;
    }

    return head;
  }
};
// 46 ms
// 30.1 MB