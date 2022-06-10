class Solution {
 public:
  long long maximumImportance(int n, vector<vector<int>>& roads) {
    vector<long long> cnt(n);

    for (auto& r : roads) {
      ++cnt[r[0]];
      ++cnt[r[1]];
    }

    sort(cnt.begin(), cnt.end());

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      ans += cnt[i - 1] * i;
    }

    return ans;
  }
};
// Runtime: 450 ms, faster than 92.42%
// Memory Usage: 113.9 MB, less than 83.42%
// 2022.6.10 at 奥盛大厦