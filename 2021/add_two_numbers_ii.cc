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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> stk1;
    stack<int> stk2;

    ListNode* cur = l1;

    while (cur) {
      stk1.push(cur->val);
      cur = cur->next;
    }

    cur = l2;
    while (cur) {
      stk2.push(cur->val);
      cur = cur->next;
    }

    ListNode* head = nullptr;
    int carry = 0;
    while (!stk1.empty() || !stk2.empty() || carry) {
      int v1, v2;

      if (stk1.empty()) {
        v1 = 0;
      } else {
        v1 = stk1.top();
        stk1.pop();
      }

      if (stk2.empty()) {
        v2 = 0;
      } else {
        v2 = stk2.top();
        stk2.pop();
      }

      int sum = v1 + v2 + carry;
      carry = sum > 9 ? 1 : 0;

      ListNode* node = new ListNode(sum % 10);
      node->next = head;
      head = node;
    }

    return head;
  }
};  // 24ms 13.1MB

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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int len1 = 0, len2 = 0;

    ListNode* cur1 = l1;
    ListNode* cur2 = l2;

    while (cur1 || cur2) {
      if (cur1) {
        ++len1;
        cur1 = cur1->next;
      }

      if (cur2) {
        ++len2;
        cur2 = cur2->next;
      }
    }

    ListNode* head = addTwo(l1, l2, len1, len2);
    if (head->val > 9) {
      ListNode* node = new ListNode(1);
      head->val = head->val % 10;

      node->next = head;
      head = node;
    }

    return head;
  }

  ListNode* addTwo(ListNode* l1, ListNode* l2, int len1, int len2) {
    if (len1 == len2 && len1 == 0) {
      return nullptr;
    } else if (len1 == len2) {
      ListNode* node = addTwo(l1->next, l2->next, --len1, --len2);

      int sum = 0;
      if (node) {
        sum = l1->val + l2->val + node->val / 10;
        node->val = node->val % 10;
        l1->next = node;
      } else {
        sum = l1->val + l2->val;
      }

      l1->val = sum;

      return l1;
    } else if (len1 > len2) {
      ListNode* node = addTwo(l1->next, l2, --len1, len2);

      int sum = 0;
      if (node) {
        sum = l1->val + node->val / 10;
        node->val = node->val % 10;
        l1->next = node;
      } else {
        sum = l1->val;
      }

      l1->val = sum;

      return l1;
    } else if (len1 < len2) {
      ListNode* node = addTwo(l1, l2->next, len1, --len2);

      int sum = 0;

      if (node) {
        sum = l2->val + node->val / 10;
        node->val = node->val % 10;
        l2->next = node;
      } else {
        sum = l2->val;
      }

      l2->val = sum;

      return l2;
    }

    return nullptr;
  }
};  // 24ms 10.1MB