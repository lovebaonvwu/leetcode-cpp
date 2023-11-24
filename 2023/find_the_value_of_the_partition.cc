class Solution {
 public:
  int findValueOfPartition(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ans = INT_MAX;
    for (int i = 1; i < nums.size(); ++i) {
      ans = min(ans, abs(nums[i] - nums[i - 1]));
    }

    return ans;
  }
};
// Runtime 143 ms
// Memory 59.1 MB