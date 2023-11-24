class Solution {
 public:
  int getMinDistance(vector<int>& nums, int target, int start) {
    int ans = INT_MAX;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == target) {
        ans = min(ans, abs(start - i));
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 9.7 MB, less than 78.78%