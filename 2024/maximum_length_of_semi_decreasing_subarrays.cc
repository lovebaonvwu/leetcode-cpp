class Solution {
 public:
  int maxSubarrayLength(vector<int>& nums) {
    stack<int> stk;

    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (stk.empty() || nums[i] > nums[stk.top()])
        stk.push(i);
    }

    int ans = 0;

    for (int i = n - 1; i >= 0; --i) {
      while (!stk.empty() && nums[i] < nums[stk.top()]) {
        ans = max(ans, i - stk.top() + 1);
        stk.pop();
      }
    }

    return ans;
  }
};
// 106 ms
// 75.38 MB