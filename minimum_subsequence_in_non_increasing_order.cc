class Solution {
 public:
  vector<int> minSubsequence(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());

    int sum = accumulate(nums.begin(), nums.end(), 0);
    int tmp = 0;

    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i) {
      if (tmp > sum) {
        break;
      }

      tmp += nums[i];
      sum -= nums[i];

      ans.push_back(nums[i]);
    }

    return ans;
  }
};
// Runtime: 24 ms, faster than 37.58%
// Memory Usage: 10.5 MB, less than 100.00%