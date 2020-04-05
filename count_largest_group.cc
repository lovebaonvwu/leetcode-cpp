class Solution {
 public:
  int countLargestGroup(int n) {
    vector<int> cnt(37);

    for (int i = 1; i <= n; ++i) {
      int sum = 0;
      int x = i;

      while (x > 0) {
        sum += x % 10;

        x /= 10;
      }

      ++cnt[sum];
    }

    int mx = 0;
    int ans = 0;

    for (int i = 0; i < cnt.size(); ++i) {
      if (cnt[i] > mx) {
        mx = cnt[i];
        ans = 1;
      } else if (cnt[i] == mx) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 100.00%