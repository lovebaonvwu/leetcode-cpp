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
  ListNode* plusOne(ListNode* head) {
    int rem = dfs(head);
    if (rem > 0) {
      ListNode* newHead = new ListNode(1);
      newHead->next = head;
      head = newHead;
    }

    return head;
  }

  int dfs(ListNode* cur) {
    if (!cur) {
      return 1;
    }

    int sum = cur->val + dfs(cur->next);
    cur->val = sum % 10;

    return sum / 10;
  }
};
// Runtime 3 ms
// Memory 8.7 MB
// 2023.2.2 at 聊城月季西路长江路