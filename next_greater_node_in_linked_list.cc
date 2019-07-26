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
  vector<int> nextLargerNodes(ListNode* head) {
    vector<int> nums;

    while (head) {
      nums.push_back(head->val);
      head = head->next;
    }

    vector<int> ans(nums.size());
    stack<int> stk;

    for (int i = nums.size() - 1; i >= 0; --i) {
      while (!stk.empty() && nums[i] >= stk.top()) {
        stk.pop();
      }

      ans[i] = stk.empty() ? 0 : stk.top();
      stk.push(nums[i]);
    }

    return ans;
  }
};  // 212ms

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
  vector<int> nextLargerNodes(ListNode* head) {
    vector<int> nums;

    while (head) {
      nums.push_back(head->val);
      head = head->next;
    }

    vector<int> ans(nums.size());
    stack<int> stk;

    for (int i = nums.size() - 1; i >= 0; --i) {
      if (stk.empty()) {
        ans[i] = 0;
      } else {
        while (!stk.empty() && nums[i] >= stk.top()) {
          stk.pop();
        }

        ans[i] = stk.empty() ? 0 : stk.top();
      }

      stk.push(nums[i]);
    }

    return ans;
  }
};  // 220ms

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
  vector<int> nextLargerNodes(ListNode* head) {
    vector<int> ans;

    ListNode* slow = head;
    ListNode* fast = head;

    while (slow) {
      fast = slow->next;

      while (fast && fast->val <= slow->val) {
        fast = fast->next;
      }

      ans.push_back(fast ? fast->val : 0);

      slow = slow->next;
    }

    return ans;
  }
};  // 1524ms