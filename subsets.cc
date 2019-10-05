class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;

    ans.push_back({});

    for (const auto& n : nums) {
      vector<vector<int>> t = ans;

      for (auto& x : t) {
        x.push_back(n);
      }

      for (auto x : t) {
        ans.push_back(x);
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 97.68%
// Memory Usage: 9.1 MB, less than 77.97%