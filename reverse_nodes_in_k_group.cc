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
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head) {
      return head;
    }

    ListNode node(0);
    ListNode* dummy = &node;

    dummy->next = head;
    ListNode* cur = head;

    int cnt = 0;
    while (cur && cnt < k) {
      ++cnt;
      cur = cur->next;
    }
    if (cnt < k) {
      return head;
    }

    stack<ListNode*> stk;
    cur = head;

    while (stk.size() < k) {
      ListNode* next = cur->next;
      cur->next = nullptr;
      stk.push(cur);
      cur = next;
    }

    ListNode* tail = reverseKGroup(cur, k);

    dummy->next = stk.top();
    cur = dummy->next;
    stk.pop();

    while (!stk.empty()) {
      cur->next = stk.top();
      stk.pop();

      cur = cur->next;
    }

    cur->next = tail;

    return dummy->next;
  }
};
// Runtime: 12 ms, faster than 91.02%
// Memory Usage: 12.6 MB, less than 5.72%
// 2021.7.18 at 奥盛大厦