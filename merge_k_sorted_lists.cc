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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) {
      return nullptr;
    }

    return mergeLists(lists, 0, lists.size() - 1);
  }

  ListNode* mergeLists(vector<ListNode*>& lists, int start, int end) {
    if (end - start >= 2) {
      int mid = (start + end) >> 1;

      return merge2Lists(mergeLists(lists, start, mid),
                         mergeLists(lists, mid + 1, end));
    }

    if (start != end) {
      return merge2Lists(lists[start], lists[end]);
    } else {
      return merge2Lists(lists[start], nullptr);
    }
  }

  ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2)
      return nullptr;

    if (!l1)
      return l2;
    if (!l2)
      return l1;

    ListNode* head = nullptr;
    ListNode* prev = nullptr;

    while (l1 && l2) {
      if (!prev) {
        prev = l1->val < l2->val ? l1 : l2;
        head = prev;
      } else {
        prev->next = l1->val < l2->val ? l1 : l2;
        prev = prev->next;
      }

      if (l1->val < l2->val) {
        l1 = l1->next;
      } else {
        l2 = l2->next;
      }
    }

    if (l1)
      prev->next = l1;
    if (l2)
      prev->next = l2;

    return head;
  }
};  // 20ms

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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) {
      return nullptr;
    }

    return mergeLists(lists, 0, lists.size() - 1);
  }

  ListNode* mergeLists(vector<ListNode*>& lists, int start, int end) {
    if (end - start >= 2) {
      ListNode* l1;
      ListNode* l2;
      int mid = (start + end) >> 1;

      l1 = mergeLists(lists, start, mid);
      l2 = mergeLists(lists, mid + 1, end);

      return merge2Lists(l1, l2);
    } else if (start != end) {
      return merge2Lists(lists[start], lists[end]);
    } else {
      return merge2Lists(lists[start], nullptr);
    }
  }

  ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2)
      return nullptr;

    if (!l1)
      return l2;
    if (!l2)
      return l1;

    ListNode* head = nullptr;
    ListNode* prev = nullptr;

    while (l1 && l2) {
      if (!prev) {
        prev = l1->val < l2->val ? l1 : l2;
        head = prev;
      } else {
        prev->next = l1->val < l2->val ? l1 : l2;
        prev = prev->next;
      }

      if (l1->val < l2->val) {
        l1 = l1->next;
      } else {
        l2 = l2->next;
      }
    }

    if (l1)
      prev->next = l1;
    if (l2)
      prev->next = l2;

    return head;
  }
};  // 36ms