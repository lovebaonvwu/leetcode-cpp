class Solution {
 public:
  int maxSum(vector<int>& nums) {
    unordered_map<int, vector<int>> mp;
    for (auto n : nums) {
      int key = 0;
      int t = n;
      while (t > 0) {
        key = max(key, t % 10);
        t /= 10;
      }

      mp[key].push_back(n);
    }

    int ans = 0;
    for (auto [_, values] : mp) {
      for (int i = 0; i < values.size(); ++i) {
        for (int j = i + 1; j < values.size(); ++j) {
          ans = max(ans, values[i] + values[j]);
        }
      }
    }

    return ans ? ans : -1;
  }
};
// 37ms
// 71.86mb