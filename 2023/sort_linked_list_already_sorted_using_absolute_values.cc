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
  ListNode* sortLinkedList(ListNode* head) {
    map<int, vector<ListNode*>> mp;

    while (head) {
      mp[head->val].push_back(head);
      head = head->next;
    }

    ListNode dummy;
    ListNode* prev = &dummy;
    for (auto& [_, nodes] : mp) {
      for (auto& node : nodes) {
        prev->next = node;
        prev = node;
      }
    }

    prev->next = nullptr;

    return dummy.next;
  }
};
// Runtime 349 ms
// Memory 107.1 MB
// 2023.1.30 at 奥盛大厦

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
  ListNode* sortLinkedList(ListNode* head) {
    ListNode* cur = head;
    ListNode* prev;
    while (cur) {
      if (cur->val < 0 && cur != head) {
        prev->next = cur->next;
        cur->next = head;
        head = cur;
        cur = prev->next;
      } else {
        prev = cur;
        cur = cur->next;
      }
    }

    return head;
  }
};
// Runtime 325 ms
// Memory 92.8 MB
// 2023.1.30 at 奥盛大厦