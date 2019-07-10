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
  bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) {
        return true;
      }
    }

    return false;
  }
};  // 12ms 9.8MB

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
  bool hasCycle(ListNode* head) {
    unordered_map<ListNode*, int> mp;

    while (head) {
      ListNode* t = head;
      head = head->next;

      t->next = nullptr;

      if (mp.find(t) != mp.end()) {
        return true;
      } else {
        mp[t] = 1;
      }
    }

    return false;
  }
};  // 16ms 12.2MB