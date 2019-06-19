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
  bool isPalindrome(ListNode* head) {
    if (!head) {
      return true;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast && fast->next) {
      fast = fast->next->next;

      ListNode* next = slow->next;
      slow->next = prev;
      prev = slow;
      slow = next;
    }

    if (!fast) {
      fast = slow;
    } else {
      fast = slow->next;
    }

    while (fast) {
      if (fast->val != prev->val) {
        return false;
      }

      fast = fast->next;
      prev = prev->next;
    }

    return true;
  }
};