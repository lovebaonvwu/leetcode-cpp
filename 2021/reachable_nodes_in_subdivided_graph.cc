class Solution {
 public:
  int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
    unordered_map<int, unordered_map<int, int>> g;

    for (auto& e : edges) {
      g[e[0]][e[1]] = g[e[1]][e[0]] = e[2];
    }

    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> visited;

    pq.push({maxMoves, 0});

    while (!pq.empty()) {
      auto [moves, node] = pq.top();
      pq.pop();

      if (visited.count(node)) {
        continue;
      }

      visited[node] = moves;

      for (auto& p : g[node]) {
        auto next = p.first;
        auto dist = p.second;

        if (visited.count(next) || moves - dist - 1 < 0) {
          continue;
        }

        pq.push({moves - dist - 1, next});
      }
    }

    int ans = visited.size();

    for (auto& e : edges) {
      int uv = visited.count(e[0]) ? visited[e[0]] : 0;
      int vu = visited.count(e[1]) ? visited[e[1]] : 0;

      ans += min(e[2], uv + vu);
    }

    return ans;
  }
};
// Runtime: 164 ms, faster than 59.28%
// Memory Usage: 46.6 MB, less than 43.89%
// 2021.9.12 at 茗筑美嘉