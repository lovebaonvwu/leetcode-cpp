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
  vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    int prev = 0, i = -1, j = -1, k = 1;

    vector<int> ans(2, -1);

    while (head) {
      if (prev && head->next &&
          (head->val > prev && head->val > head->next->val ||
           head->val < prev && head->val < head->next->val)) {
        if (i < 0) {
          i = k;
        }

        if (i > 0 && j > 0) {
          ans[0] = ans[1] < 0 ? (k - j) : min(ans[0], k - j);
          ans[1] = max(ans[1], k - i);
        }

        j = k;
      }

      prev = head->val;

      ++k;

      head = head->next;
    }

    return ans;
  }
};
// Runtime: 216 ms, faster than 63.64%
// Memory Usage: 113.3 MB, less than 100.00%
// 2021.11.1 at 奥盛大厦