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
  ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode ans(0);
    ans.next = head;

    ListNode* prev = &ans;

    while (head) {
      int sum = 0;

      ListNode* cur = head;

      while (cur) {
        sum += cur->val;

        if (sum == 0) {
          if (prev) {
            prev->next = cur->next;
          }

          head = cur->next;
        }

        cur = cur->next;
      }

      prev = head;

      if (head) {
        head = head->next;
      }
    }

    return ans.next;
  }
};
// Runtime: 8 ms, faster than 99.58%
// Memory Usage: 10.8 MB, less than 97.48%

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
  ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode ans(0);
    ans.next = head;

    unordered_map<int, ListNode*> mp;

    ListNode* cur = &ans;

    int presum = 0;
    while (cur) {
      presum += cur->val;

      if (mp.count(presum)) {
        cur = mp[presum]->next;

        int sum = presum + cur->val;

        while (sum != presum) {
          mp.erase(sum);

          cur = cur->next;

          sum += cur->val;
        }

        mp[presum]->next = cur->next;

      } else {
        mp[presum] = cur;
      }

      cur = cur->next;
    }

    return ans.next;
  }
};
// Runtime: 12 ms, faster than 93.71%
// Memory Usage: 11.9 MB, less than 43.19%