class Solution {
 public:
  int longestEqualSubarray(vector<int>& nums, int k) {
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < nums.size(); ++i) {
      mp[nums[i]].push_back(i);
    }

    int ans = 1;
    for (auto& [_, ids] : mp) {
      for (int i = 0, j = 0; j < ids.size(); ++j) {
        if ((ids[j] - ids[i] + 1) - (j - i + 1) > k) {
          ++i;
        }
        ans = max(ans, j - i + 1);
      }
    }

    return ans;
  }
};
// 383ms
// 226.52MB