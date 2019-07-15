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
  ListNode* detectCycle(ListNode* head) {
    auto slow = head;
    auto fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) {
        break;
      }
    }

    if (!fast || !fast->next) {
      return nullptr;
    }

    slow = head;

    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }

    return slow;
  }
};  // 8ms 9.6MB

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
  ListNode* detectCycle(ListNode* head) {
    unordered_map<ListNode*, int> mp;

    while (head) {
      if (mp.find(head) != mp.end()) {
        return head;
      } else {
        mp[head] = 1;
      }

      head = head->next;
    }

    return nullptr;
  }
};  // 28ms 12.5MB