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
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int cnt = 0;

    ListNode* cur = headA;
    while (cur) {
      ++cnt;

      cur = cur->next;
    }

    cur = headB;
    while (cur) {
      --cnt;
      cur = cur->next;
    }

    ListNode* curA = headA;
    ListNode* curB = headB;

    while (cnt != 0) {
      if (cnt > 0) {
        curA = curA->next;
        --cnt;
      } else if (cnt < 0) {
        curB = curB->next;
        ++cnt;
      }
    }

    while (curA != curB) {
      curA = curA->next;
      curB = curB->next;
    }

    return curA;
  }
};  // 52ms

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
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    unordered_map<ListNode*, int> mp;

    ListNode* cur = headA;
    while (cur) {
      mp[cur] = 1;

      cur = cur->next;
    }

    cur = headB;
    while (cur) {
      if (mp[cur]) {
        return cur;
      }

      cur = cur->next;
    }

    return nullptr;
  }
};  // 64ms

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
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* pa = headA;
    ListNode* pb = headB;

    if (!pa || !pb) {
      return nullptr;
    }

    while (pa != pb) {
      pa = pa->next;
      pb = pb->next;

      if (pa == pb) {
        return pa;
      }

      if (pa == nullptr) {
        pa = headB;
      }

      if (pb == nullptr) {
        pb = headA;
      }
    }

    return pa;
  }
};
// Runtime: 40 ms, faster than 84.42%
// Memory Usage: 14.5 MB, less than 68.08%