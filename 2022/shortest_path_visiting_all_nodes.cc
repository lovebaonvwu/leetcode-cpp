class Solution {
 public:
  int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    int target = (1 << n) - 1;

    vector<vector<int>> visited(n, vector<int>(1 << n));

    queue<pair<int, int>> q;
    for (int i = 0; i < graph.size(); ++i) {
      q.push({i, 1 << i});
    }

    int ans = 0;

    while (!q.empty()) {
      int cnt = q.size();

      while (cnt-- > 0) {
        auto [node, state] = q.front();
        q.pop();

        if (state == target) {
          return ans;
        }

        if (visited[node][state]) {
          continue;
        }

        visited[node][state] = 1;
        for (auto next : graph[node]) {
          q.push({next, state | (1 << next)});
        }
      }

      ++ans;
    }

    return -1;
  }
};
// Runtime: 40 ms, faster than 73.10%
// Memory Usage: 19.8 MB, less than 33.66%
// 2022.2.26 at 茗筑美嘉