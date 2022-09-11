class Solution {
 public:
  int mostFrequentEven(vector<int>& nums) {
    unordered_map<int, int> cnt;

    int maxcnt = 0;
    int ans = -1;
    for (auto n : nums) {
      if (n % 2 != 0) {
        continue;
      }

      ++cnt[n];

      if (cnt[n] > maxcnt) {
        maxcnt = cnt[n];
        ans = n;
      } else if (cnt[n] == maxcnt && n < ans) {
        ans = n;
      }
    }

    return ans;
  }
};
// Runtime: 103 ms, faster than 25.00%
// Memory Usage: 38.1 MB, less than 25.00%
// 2022.9.11 at 茗筑美嘉