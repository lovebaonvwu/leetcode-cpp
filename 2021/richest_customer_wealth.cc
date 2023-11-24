class Solution {
 public:
  int maximumWealth(vector<vector<int>>& accounts) {
    int ans = 0;

    for (auto& a : accounts) {
      int sum = 0;
      for (auto m : a) {
        sum += m;
      }

      ans = max(ans, sum);
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 93.51%
// Memory Usage: 8.1 MB, less than 61.01%