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
  int numComponents(ListNode* head, vector<int>& G) {
    int st[10000]{};

    for (const auto& g : G) {
      st[g] = 1;
    }

    int ans = 0;

    while (head) {
      if (st[head->val] && (!head->next || !st[head->next->val]))
        ++ans;

      head = head->next;
    }

    return ans;
  }
};
// Runtime: 24 ms, faster than 99.15%
// Memory Usage: 12.7 MB, less than 89.47%

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
  int numComponents(ListNode* head, vector<int>& G) {
    int st[10000]{};

    for (const auto& g : G) {
      st[g] = 1;
    }

    int cnt = 0;
    int ans = 0;

    while (head) {
      if (st[head->val]) {
        ++cnt;
      } else if (cnt > 0) {
        cnt = 0;
        ++ans;
      }

      head = head->next;
    }

    if (cnt) {
      ++ans;
    }

    return ans;
  }
};
// Runtime: 36 ms, faster than 90.53%
// Memory Usage: 12.8 MB, less than 84.21%

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
  int numComponents(ListNode* head, vector<int>& G) {
    unordered_set<int> st(G.begin(), G.end());

    int cnt = 0;
    int ans = 0;

    while (head) {
      bool hole = false;

      if (st.count(head->val)) {
        ++cnt;
      } else {
        hole = true;
      }

      if (cnt > 0 && hole) {
        cnt = 0;
        ++ans;
      }
      head = head->next;
    }

    if (cnt) {
      ++ans;
    }

    return ans;
  }
};
// Runtime: 48 ms, faster than 42.52%
// Memory Usage: 14.5 MB, less than 68.42%