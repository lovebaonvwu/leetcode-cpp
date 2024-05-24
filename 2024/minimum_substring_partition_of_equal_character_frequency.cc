class Solution {
 public:
  int minimumSubstringsInPartition(string s) {
    int n = s.size();
    int ans = INT_MAX;
    vector<int> cached(n, -1);

    function<bool(const vector<int>&)> isBalanced =
        [](const vector<int>& cnt) -> bool {
      int mx = 0;
      int mi = INT_MAX;
      for (auto c : cnt) {
        if (c > 0) {
          mx = max(mx, c);
          mi = min(mi, c);
        }
      }

      return mx == mi;
    };

    function<int(int)> dfs = [&](int i) -> int {
      if (i == n)
        return 0;

      if (cached[i] != -1)
        return cached[i];

      int ret = INT_MAX;
      vector<int> cnt(26);
      for (int j = i; j < n; ++j) {
        ++cnt[s[j] - 'a'];
        if (isBalanced(cnt)) {
          ret = min(ret, 1 + dfs(j + 1));
        }
      }

      return cached[i] = ret;
    };

    return dfs(0);
  }
};
// 634 ms
// 18.60 MB