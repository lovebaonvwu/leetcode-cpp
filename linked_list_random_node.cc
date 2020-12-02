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
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least
     one node. */
  Solution(ListNode* head) {
    h = head;

    while (head) {
      ++sz;
      head = head->next;
    }
  }

  /** Returns a random node's value. */
  int getRandom() {
    int r = rand() % sz;

    ListNode* t = h;

    while (r-- > 0) {
      t = t->next;
    }

    return t->val;
  }

 private:
  int sz = 0;
  ListNode* h;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// Runtime: 36 ms, faster than 38.77%
// Memory Usage: 16.9 MB, less than 32.60%

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
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least
     one node. */
  Solution(ListNode* head) { this->head = head; }

  /** Returns a random node's value. */
  int getRandom() {
    ListNode* node = head;
    int i = 1;

    int val = head->val;

    while (node) {
      int r = rand() % i;

      if (r == 0) {
        val = node->val;
      }

      ++i;
      node = node->next;
    }

    return val;
  }

 private:
  ListNode* head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// Runtime: 28 ms, faster than 94.27%
// Memory Usage: 16.9 MB, less than 65.86%