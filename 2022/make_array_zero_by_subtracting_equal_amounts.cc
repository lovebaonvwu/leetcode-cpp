class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    int cnt[101] = {0};

    int ans = 0;

    for (auto n : nums) {
      if (n > 0) {
        ans += cnt[n] == 0;
        ++cnt[n];
      }
    }

    return ans;
  }
};
// Runtime: 6 ms, faster than 100.00%
// Memory Usage: 8.2 MB, less than 100.00%
// 2022.7.31 at 茗筑美嘉