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
  ListNode* swapNodes(ListNode* head, int k) {
    int cnt = 0;

    ListNode* cur = head;
    while (cur) {
      ++cnt;
      cur = cur->next;
    }

    int kk = cnt - k + 1;

    if (k == kk) {
      return head;
    }

    if (k > kk) {
      swap(k, kk);
    }

    cur = head;
    while (k > 0 || kk > 0) {
      --k, --kk;

      ListNode* tmp;
      if (k == 0) {
        tmp = cur;
      }

      if (kk == 0) {
        swap(tmp->val, cur->val);
        break;
      }

      cur = cur->next;
    }

    return head;
  }
};
// Runtime: 1924 ms, faster than 77.78%
// Memory Usage: 180.7 MB, less than 11.11%

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
  ListNode* swapNodes(ListNode* head, int k) {
    ListNode* slow = nullptr;
    ListNode* fast = head;
    ListNode* first = nullptr;
    ListNode* second = nullptr;

    for (int i = 0; i < k - 1; ++i) {
      fast = fast->next;
    }

    first = fast;
    slow = head;

    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }

    second = slow;

    swap(first->val, second->val);

    return head;
  }
};
// Runtime: 904 ms, faster than 77.78%
// Memory Usage: 180.6 MB, less than 11.11%