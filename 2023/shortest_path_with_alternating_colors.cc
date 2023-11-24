class Solution {
 public:
  vector<int> shortestAlternatingPaths(int n,
                                       vector<vector<int>>& redEdges,
                                       vector<vector<int>>& blueEdges) {
    vector<vector<pair<int, int>>> g(n);
    for (auto& redEdge : redEdges) {
      g[redEdge[0]].push_back({redEdge[1], 0});
    }
    for (auto& blueEdge : blueEdges) {
      g[blueEdge[0]].push_back({blueEdge[1], 1});
    }

    vector<vector<bool>> visited(n, vector<bool>(2));
    visited[0][0] = true;
    visited[0][1] = true;

    queue<vector<int>> q;
    q.push({0, 0, -1});
    vector<int> ans(n, -1);
    ans[0] = 0;

    while (!q.empty()) {
      auto node = q.front();

      int cur = node[0];
      int dist = node[1];
      int prevColor = node[2];

      q.pop();

      for (auto& [next, color] : g[cur]) {
        if (!visited[next][color] && color != prevColor) {
          visited[next][color] = true;
          q.push({next, dist + 1, color});
          if (ans[next] == -1) {
            ans[next] = dist + 1;
          }
        }
      }
    }

    return ans;
  }
};
// Runtime 24 ms
// Memory 15.4 MB
// 2023.2.12 at 茗筑美嘉