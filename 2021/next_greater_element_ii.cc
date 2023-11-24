class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> stk;
    vector<int> ans(nums.size());

    for (int i = nums.size() - 2; i >= 0; --i) {
      stk.push(nums[i]);
    }

    for (int i = nums.size() - 1; i >= 0; --i) {
      while (!stk.empty() && nums[i] >= stk.top()) {
        stk.pop();
      }

      ans[i] = stk.empty() ? -1 : stk.top();

      stk.push(nums[i]);
    }

    return ans;
  }
};  // 76ms