class Solution {
 public:
  int validSubarraySize(vector<int>& nums, int threshold) {
    stack<int> stk;

    nums.push_back(0);

    for (int i = 0; i < nums.size(); ++i) {
      while (!stk.empty() && nums[i] < nums[stk.top()]) {
        int h = nums[stk.top()];
        stk.pop();

        int w = i - (stk.empty() ? -1 : stk.top()) - 1;
        if (h * w > threshold) {
          return w;
        }
      }
      stk.push(i);
    }

    return -1;
  }
};
// Runtime: 316 ms, faster than 74.31%
// Memory Usage: 94.5 MB, less than 52.11%
// 2022.8.5 at 奥盛大厦