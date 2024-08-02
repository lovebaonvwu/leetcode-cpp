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
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> st(begin(nums), end(nums));

    ListNode root;
    root.next = head;
    ListNode* prev = &root;
    ListNode* cur = head;

    while (cur) {
      if (st.find(cur->val) != st.end()) {
        prev->next = cur->next;
      } else {
        prev = cur;
      }
      cur = cur->next;
    }

    return root.next;
  }
};
// 427 ms
// 258.52 MB
