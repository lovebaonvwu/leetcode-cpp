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
  string gameResult(ListNode* head) {
    int ans = 0;

    while (head) {
      int even_value = head->val;
      head = head->next;

      int odd_value = head->val;
      head = head->next;

      ans += odd_value > even_value ? 1 : -1;
    }

    return ans == 0 ? "Tie" : ans > 0 ? "Odd" : "Even";
  }
};
// 4 ms
// 23.74 MB