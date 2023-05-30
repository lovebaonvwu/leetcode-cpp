class Solution {
 public:
  long long minimumCost(string s) {
    long long ans = 0;

    for (int i = 1, n = s.size(); i < n; ++i) {
      if (s[i] != s[i - 1]) {
        ans += min(i, n - i);
      }
    }

    return ans;
  }
};
// Runtime 24 ms
// Memory 12.1 MB