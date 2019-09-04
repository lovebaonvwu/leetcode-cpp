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
  void reorderList(ListNode* head) {
    if (!head || !head->next) {
      return;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    ListNode* prev = nullptr;
    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    prev->next = nullptr;

    prev = nullptr;
    while (slow) {
      ListNode* tmp = slow;
      slow = slow->next;
      tmp->next = prev;
      prev = tmp;
    }

    slow = prev;
    fast = head->next;
    prev = head;

    while (slow && fast) {
      prev->next = slow;
      slow = slow->next;

      prev = prev->next;

      prev->next = fast;
      fast = fast->next;

      prev = prev->next;
    }

    if (slow) {
      prev->next = slow;
    }
  }
};  // 44ms

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
  void reorderList(ListNode* head) {
    if (!head) {
      return;
    }

    deque<ListNode*> dq;

    ListNode* cur;

    while (head) {
      cur = head;
      head = head->next;
      cur->next = nullptr;

      dq.push_back(cur);
    }

    head = dq.front();
    dq.pop_front();

    cur = head;
    while (!dq.empty()) {
      cur->next = dq.back();
      cur = cur->next;
      dq.pop_back();

      if (!dq.empty()) {
        cur->next = dq.front();
        cur = cur->next;
        dq.pop_front();
      }
    }
  }
};  // 48ms

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
  void reorderList(ListNode* head) {
    if (!head) {
      return;
    }

    vector<ListNode*> v;

    ListNode* cur;
    while (head) {
      cur = head;
      head = head->next;

      cur->next = nullptr;

      v.push_back(cur);
    }

    int i = 0;
    int j = v.size() - 1;

    head = v[0];
    ++i;

    cur = head;
    while (i <= j) {
      cur->next = v[j--];
      cur = cur->next;

      if (i <= j) {
        cur->next = v[i++];
        cur = cur->next;
      }
    }
  }
};  // 48ms