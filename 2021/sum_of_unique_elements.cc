class Solution {
 public:
  int sumOfUnique(vector<int>& nums) {
    int cnt[101] = {0};

    int ans = 0;
    for (auto n : nums) {
      ++cnt[n];
      if (cnt[n] == 1) {
        ans += n;
      } else if (cnt[n] == 2) {
        ans -= n;
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.8 MB, less than 76.53%