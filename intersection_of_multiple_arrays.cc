class Solution {
 public:
  vector<int> intersection(vector<vector<int>>& nums) {
    vector<int> cnt(1001);

    for (auto& num : nums) {
      for (auto n : num) {
        ++cnt[n];
      }
    }

    vector<int> ans;
    for (int i = 0; i < cnt.size(); ++i) {
      if (cnt[i] == nums.size()) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// Runtime: 18 ms, faster than 51.71%
// Memory Usage: 12.3 MB, less than 78.05%
// 2022.6.3 at 茗筑美嘉