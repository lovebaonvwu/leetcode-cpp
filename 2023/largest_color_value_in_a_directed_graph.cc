class Solution {
 public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.size();
    vector<vector<int>> g(n);
    vector<vector<int>> cnt(n, vector<int>(26));
    vector<int> visited(n);

    for (auto& e : edges) {
      g[e[0]].push_back(e[1]);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, dfs(g, cnt, visited, colors, i));
    }

    return ans == INT_MAX ? -1 : ans;
  }

  int dfs(vector<vector<int>>& g,
          vector<vector<int>>& cnt,
          vector<int>& visited,
          const string& s,
          int cur) {
    if (!visited[cur]) {
      visited[cur] = 1;

      for (auto& next : g[cur]) {
        if (dfs(g, cnt, visited, s, next) == INT_MAX) {
          return INT_MAX;
        }

        for (int k = 0; k < 26; ++k) {
          cnt[cur][k] = max(cnt[cur][k], cnt[next][k]);
        }
      }

      ++cnt[cur][s[cur] - 'a'];
      visited[cur] = 2;
    }

    return visited[cur] == 2 ? cnt[cur][s[cur] - 'a'] : INT_MAX;
  }
};
// Runtime 621 ms
// Memory 204.5 MB