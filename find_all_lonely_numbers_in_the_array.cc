class Solution {
 public:
  vector<int> findLonely(vector<int>& nums) {
    unordered_map<int, int> mp;

    for (auto n : nums) {
      ++mp[n];
    }

    vector<int> ans;
    for (auto n : nums) {
      if (mp[n] == 1 && mp.find(n - 1) == mp.end() &&
          mp.find(n + 1) == mp.end()) {
        ans.push_back(n);
      }
    }

    return ans;
  }
};
// Runtime: 396 ms, faster than 53.33%
// Memory Usage: 167.3 MB, less than 46.67%
// 2022.1.24 at 奥盛大厦