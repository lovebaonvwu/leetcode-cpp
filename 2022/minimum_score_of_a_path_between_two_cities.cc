class Solution {
 public:
  int minScore(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> g(n + 1);
    for (auto& road : roads) {
      g[road[0]].push_back({road[1], road[2]});
      g[road[1]].push_back({road[0], road[2]});
    }

    vector<int> visited(n + 1);
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    int ans = INT_MAX;
    while (!q.empty()) {
      int node = q.front();
      q.pop();

      for (auto& next : g[node]) {
        ans = min(ans, next.second);
        if (visited[next.first] == 0) {
          q.push(next.first);
          visited[next.first] = 1;
        }
      }
    }

    return ans;
  }
};
// Runtime 484 ms
// Memory 126.4 MB
// 2022.12.30 at 奥盛大厦