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
  vector<ListNode*> splitListToParts(ListNode* root, int k) {
    int cnt = 0;

    for (ListNode* cur = root; cur; cur = cur->next) {
      ++cnt;
    }

    int a = cnt / k;
    int b = cnt % k;

    vector<ListNode*> ans(k);
    int i = 0;

    while (root) {
      ListNode* prev = nullptr;

      ans[i++] = root;

      for (int i = 0; i < a; ++i) {
        prev = root;
        root = root->next;
      }

      if (b-- > 0) {
        prev = root;
        root = root->next;
      }

      prev->next = nullptr;
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 54.58%
// Memory Usage: 10.1 MB, less than 9.09%

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
  vector<ListNode*> splitListToParts(ListNode* root, int k) {
    int cnt = 0;

    ListNode* cur = root;
    while (cur) {
      ++cnt;
      cur = cur->next;
    }

    int a = cnt / k;
    int b = cnt % k;

    vector<ListNode*> ans;

    while (root) {
      ListNode head{0};
      ListNode* prev = &head;

      head.next = root;

      for (int i = 0; i < a; ++i) {
        prev = root;
        root = root->next;
      }

      if (b-- > 0) {
        prev = root;
        root = root->next;
      }

      prev->next = nullptr;

      ans.push_back(head.next);
    }

    while (ans.size() < k) {
      ans.push_back({});
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 54.58%
// Memory Usage: 10 MB, less than 9.09%