class Solution {
 public:
  int numWays(string s) {
    int cnt = 0;
    for (auto c : s) {
      cnt += c == '1';
    }

    if (cnt % 3 != 0) {
      return 0;
    }

    int n = s.size();
    int mod = 1e9 + 7;
    if (cnt == 0) {
      return 1LL * (n - 2) * (n - 1) / 2 % mod;
    }

    int cnt1 = 0, cnt2 = 0;
    int a = 0, b = 0;
    cnt /= 3;
    for (int i = 0; i < n; ++i) {
      cnt1 += s[i] == '1';
      cnt2 += s[i] == '1';

      a += cnt1 == cnt;
      b += cnt2 == cnt * 2;
    }

    return 1LL * a * b % mod;
  }
};
// Runtime: 54 ms, faster than 54.63%
// Memory Usage: 14 MB, less than 28.96%
// 2022.8.26 at 奥盛大厦