class Solution {
 public:
  int largestCombination(vector<int>& candidates) {
    int ans = 0;

    for (int i = 0; i < 30; ++i) {
      int cnt = 0;
      for (auto c : candidates) {
        cnt += (c >> i) & 1;
      }

      ans = max(ans, cnt);
    }

    return ans;
  }
};
// Runtime: 136 ms, faster than 66.67%
// Memory Usage: 57.6 MB, less than 33.33%
// 2022.5.15 at 茗筑美嘉