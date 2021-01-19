class Solution {
 public:
  int tupleSameProduct(vector<int>& nums) {
    unordered_map<int, int> mp;

    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        ++mp[nums[i] * nums[j]];
      }
    }

    int ans = 0;

    for (auto& m : mp) {
      ans += (1 + m.second - 1) * (m.second - 1) / 2;
    }

    return ans * 8;
  }
};
// Runtime: 488 ms, faster than 81.82%
// Memory Usage: 81.7 MB, less than 100.00%