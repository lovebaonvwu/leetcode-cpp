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
  ListNode* mergeNodes(ListNode* head) {
    ListNode* dummy = new ListNode;
    ListNode* cur = dummy;

    int sum = 0;

    head = head->next;

    while (head) {
      if (head->val == 0) {
        ListNode* node = new ListNode(sum);

        cur->next = node;
        cur = node;

        sum = 0;

      } else {
        sum += head->val;
      }

      head = head->next;
    }

    return dummy->next;
  }
};
// Runtime: 1056 ms, faster than 21.05%
// Memory Usage: 274.5 MB, less than 5.26%
// 2022.2.21 at 奥盛大厦

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
  ListNode* mergeNodes(ListNode* head) {
    ListNode* cur = head->next;
    ListNode* start = head;

    while (cur) {
      if (cur->val == 0) {
        if (!cur->next) {
          start->next = nullptr;
        } else {
          start->next = cur;
          start = cur;
        }
      } else {
        start->val += cur->val;
      }

      cur = cur->next;
    }

    return head;
  }
};
// Runtime: 843 ms, faster than 84.21%
// Memory Usage: 253.1 MB, less than 36.84%
// 2022.2.21 at 奥盛大厦