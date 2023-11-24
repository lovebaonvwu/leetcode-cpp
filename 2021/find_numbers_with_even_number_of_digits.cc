class Solution {
 public:
  int findNumbers(vector<int>& nums) {
    int ans = 0;

    for (auto n : nums) {
      int cnt = 0;

      while (n > 0) {
        ++cnt;
        n /= 10;
      }

      if (cnt % 2 == 0) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 98.34%
// Memory Usage: 8.8 MB, less than 100.00%