class Solution {
  int calcDis(string& a, string& b) {
    int ret = b.size();

    for (int i = 1; i <= min(a.size(), b.size()); ++i) {
      if (a.substr(a.size() - i) == b.substr(0, i)) {
        ret = b.size() - i;
      }
    }

    return ret;
  }

 public:
  string shortestSuperstring(vector<string>& words) {
    int n = words.size();

    vector<vector<int>> dis(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        dis[i][j] = calcDis(words[i], words[j]);
        dis[j][i] = calcDis(words[j], words[i]);
      }
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
    vector<vector<int>> parent(1 << n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i) {
      dp[1 << i][i] = words[i].size();
    }

    for (int s = 1; s < (1 << n); ++s) {
      for (int i = 0; i < n; ++i) {
        if (!(s & (1 << i))) {
          continue;
        }

        int prev = s - (1 << i);

        for (int j = 0; j < n; ++j) {
          if (!(prev & (1 << j))) {
            continue;
          }

          if (dp[prev][j] + dis[j][i] < dp[s][i]) {
            dp[s][i] = dp[prev][j] + dis[j][i];
            parent[s][i] = j;
          }
        }
      }
    }

    auto it = min_element(begin(dp.back()), end(dp.back()));
    int cur = it - begin(dp.back());

    int s = (1 << n) - 1;

    string ans;

    while (s) {
      int prev = parent[s][cur];

      if (prev < 0) {
        ans = words[cur] + ans;
      } else {
        ans = words[cur].substr(words[cur].size() - dis[prev][cur]) + ans;
      }

      s &= ~(1 << cur);

      cur = prev;
    }

    return ans;
  }
};
// Runtime: 72 ms, faster than 68.66%
// Memory Usage: 20.6 MB, less than 37.31%