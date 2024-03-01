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
  ListNode* frequenciesOfElements(ListNode* head) {
    unordered_map<int, int> cnt;

    while (head) {
      ++cnt[head->val];
      head = head->next;
    }

    ListNode* cur = new ListNode(0);
    head = cur;
    for (auto [_, v] : cnt) {
      ListNode* node = new ListNode(v);
      cur->next = node;
      cur = node;
    }

    return head->next;
  }
};
// 278 ms
// 204.03 MB