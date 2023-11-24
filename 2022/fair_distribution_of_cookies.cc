class Solution {
  int cnt[8];
  int ans = INT_MAX;

 public:
  int distributeCookies(vector<int>& cookies, int k) {
    dfs(cookies, k, 0);
    return ans;
  }

  void dfs(vector<int>& cookies, int k, int cur) {
    if (cur == cookies.size()) {
      int curMax = *max_element(begin(cnt), end(cnt));
      ans = min(ans, curMax);
      return;
    }

    for (int i = 0; i < k; ++i) {
      cnt[i] += cookies[cur];
      dfs(cookies, k, cur + 1);
      cnt[i] -= cookies[cur];
    }
  }
};
// Runtime: 1124 ms, faster than 36.00%
// Memory Usage: 7 MB, less than 18.99%
// 2022.6.14 at 奥盛大厦

class Solution {
  int cnt[8];

 public:
  int distributeCookies(vector<int>& cookies, int k) {
    int lo = 1, hi = INT_MAX;

    while (lo < hi) {
      int md = lo + (hi - lo) / 2;
      memset(cnt, 0, sizeof(cnt));

      if (dfs(cookies, k, md, 0)) {
        hi = md;
      } else {
        lo = md + 1;
      }
    }

    return lo;
  }

  bool dfs(vector<int>& cookies, int k, int limit, int cur) {
    if (cur == cookies.size()) {
      return true;
    }

    for (int i = 0; i < k; ++i) {
      if (cnt[i] + cookies[cur] > limit) {
        continue;
      }

      cnt[i] += cookies[cur];
      if (dfs(cookies, k, limit, cur + 1)) {
        return true;
      }
      cnt[i] -= cookies[cur];
    }

    return false;
  }
};
// Runtime: 3 ms, faster than 97.90%
// Memory Usage: 6.8 MB, less than 90.81%
// 2022.6.14 at 奥盛大厦