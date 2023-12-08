class Solution {
 public:
  long long maximumScoreAfterOperations(vector<vector<int>>& edges,
                                        vector<int>& values) {
    unordered_map<int, vector<int>> g;
    for (auto& e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }

    unordered_map<int, long long> sum;
    function<long long(int, int)> calc_sum = [&](int cur,
                                                 int parent) -> long long {
      if (g[cur].size() == 1 && cur != 0) {
        return values[cur];
      }

      long long value = 0;
      for (auto& next : g[cur]) {
        if (next == parent)
          continue;
        value += calc_sum(next, cur);
      }

      sum[cur] = value;
      return value + values[cur];
    };

    function<long long(int, int)> dfs = [&](int cur, int parent) -> long long {
      if (g[cur].size() == 1 && cur != 0) {
        return 0;
      }

      long long value = values[cur];
      for (auto& next : g[cur]) {
        if (next == parent)
          continue;
        value += dfs(next, cur);
      }

      return max(value, sum[cur]);
    };

    calc_sum(0, -1);
    return dfs(0, -1);
  }
};
// 403ms
// 191.66MB