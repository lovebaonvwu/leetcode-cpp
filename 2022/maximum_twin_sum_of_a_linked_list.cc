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
  int pairSum(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* prev = nullptr;
    ListNode* cur = slow;

    while (cur) {
      ListNode* next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }

    int ans = 0;

    while (prev) {
      ans = max(ans, head->val + prev->val);

      head = head->next;
      prev = prev->next;
    }

    return ans;
  }
};
// Runtime: 324 ms, faster than 10.00%
// Memory Usage: 116.5 MB, less than 20.00%
// 2022.1.9 at 奥盛大厦

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
  int pairSum(ListNode* head) {
    vector<int> nums;

    while (head) {
      nums.push_back(head->val);

      head = head->next;
    }

    int ans = 0;

    for (int i = 0; i < nums.size(); ++i) {
      ans = max(ans, nums[i] + nums[nums.size() - i - 1]);
    }

    return ans;
  }
};
// Runtime: 313 ms
// Memory Usage : 126.8 MB
// 2022.1.9 at 奥盛大厦